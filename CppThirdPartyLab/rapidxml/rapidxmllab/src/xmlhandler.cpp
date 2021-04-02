#include "xmlhandler.h"
#include <cstring>
#include <cstdarg>
#include <iostream>
#include <fstream>

namespace
{
	std::vector<std::string> SplitString(const std::string& str, const char* delim)
	{
		std::vector<std::string> result;
		size_t delim_len = strlen(delim);
		std::string::size_type pos1 = 0;
		std::string::size_type pos2 = str.find(delim);

		while (pos2 != std::string::npos)
		{
			result.push_back(std::string(str, pos1, pos2 - pos1));

			pos1 = pos2 + delim_len;
			pos2 = str.find(delim, pos1);
		}

		if (pos1 != str.length())
		{
			result.push_back(std::string(str, pos1));
		}

		return result;
	}

	std::string StringFormat(const char* fmt, ...)
	{
		int buffer_len = 1024;
		char* buffer = new char[buffer_len] {};
		int str_len = -1;

		do
		{
			va_list ap;
			va_start(ap, fmt);
			str_len = vsnprintf(buffer, buffer_len, fmt, ap);

			if (str_len >= buffer_len) {
				str_len = -1;

				char* tmp_buffer = new char[buffer_len * 2]{};
				delete[] buffer;
				buffer_len *= 2;
				buffer = tmp_buffer;
			}
			va_end(ap);
		} while (str_len == -1);

		std::string str = buffer;
		delete[] buffer;

		return str;
	}
}

XmlHandler::XmlHandler(const char* file_name) : file_(nullptr), filename_(file_name ? file_name : "nofile"), parsed_(false)
{
}

XmlHandler::~XmlHandler()
{
	if (file_)
		delete file_;
}

bool XmlHandler::Parse(const char *file_name)
{
	if (file_name) {
		filename_ = file_name;
	}

	try
	{
		XmlFile *tmp_file = new XmlFile(filename_.c_str());
		if (file_)
			delete file_;
		file_ = tmp_file;

		doc_.clear();
		parsed_ = false;
		lasterror_.clear();

		doc_.parse<0>(file_->data()); // 0 means default parse flags
	}
	catch (rapidxml::parse_error e)
	{
		std::string error_info = std::string("parse file error: ") + e.what();			// for parse failed
		this->MakeLastError(error_info.c_str());
		return false;
	}
	catch (std::runtime_error e)
	{
		this->MakeLastError(e.what());	// for openfile failed
		return false;
	}

	parsed_ = true;
	return true;
}

XmlNode XmlHandler::GetNode(const char* xml_path) const
{
	if (!parsed_)
	{
		const_cast<XmlHandler*>(this)->MakeLastError("file not parsed");
		return nullptr;
	}

	auto path_node = doc_.first_node();
	if (!path_node) {
		const_cast<XmlHandler*>(this)->MakeLastError("file has no root node");
		return nullptr;
	}

	std::vector<std::string> node_list = SplitString(xml_path, "/");

	// 必须包括根节点
	if (node_list.size() <= 1) {
		const_cast<XmlHandler*>(this)->MakeLastError("cannot get root node value");
		return nullptr;
	}

	if (node_list[0] != path_node->name()) {
		const_cast<XmlHandler*>(this)->MakeLastError(StringFormat("root[%s] != %s", path_node->name(), node_list[0].c_str()));
		return nullptr;
	}

	for (size_t i = 1; i < node_list.size(); ++i) {
		auto node_tmp = path_node->first_node(node_list[i].c_str());
		if (!node_tmp) {
			const_cast<XmlHandler*>(this)->MakeLastError(StringFormat("no node[%s]", node_list[i].c_str()));
			return nullptr;
		}

		path_node = node_tmp;
	}

	return path_node;
}

const char * XmlHandler::GetValueStr(const char *xml_path) const
{
	if (!parsed_) {
		const_cast<XmlHandler*>(this)->MakeLastError("file not parsed");
		return nullptr;
	}

	XmlNode path_node = this->GetNode(xml_path);
	if (!path_node)
	{
		return nullptr;
	}

	// 没有一个值, 底层返回空字符串, 但此处认为获取失败
	if (strlen(path_node.GetValue()) == 0)
		return nullptr;

	return path_node.GetValue();
}

bool XmlHandler::SetValueStr(const char* xml_path, const char *value)
{
	if (filename_ == "nofile") {
		this->MakeLastError("not set a filename yet");
		return false;
	}

	if (!parsed_) {
		this->MakeLastError("file not parsed");
		return false;
	}

	std::vector<std::string> node_list = SplitString(xml_path, "/");
	if (node_list.size() <= 0) {
		this->MakeLastError("empty xml path");
		return false;
	}

	auto path_node = doc_.first_node();
	if (!path_node) {
		// 创建根节点
		char *node_name = doc_.allocate_string(node_list[0].c_str());
		path_node = doc_.allocate_node(rapidxml::node_element, node_name, "");
		doc_.append_node(path_node);
	}

	if (node_list[0] != path_node->name()) {
		this->MakeLastError(StringFormat("root[%s] != %s", path_node->name(), node_list[0].c_str()));
		return false;
	}

	for (size_t i = 1; i < node_list.size(); ++i) {
		auto node_tmp = path_node->first_node(node_list[i].c_str());
		if (node_tmp && i == node_list.size()-1) {
			path_node->remove_node(node_tmp);	// note: 底层似乎没有直接修改的接口, 因此这里先删除, 后添加
			node_tmp = nullptr;
		}

		if (!node_tmp) {
			char *node_name = doc_.allocate_string(node_list[i].c_str());
			char *node_value = doc_.allocate_string((i == node_list.size()-1) ? value : "");
			node_tmp = doc_.allocate_node(rapidxml::node_element, node_name, node_value);
			path_node->append_node(node_tmp);
		}

		path_node = node_tmp;
	}

	return true;
}

bool XmlHandler::SyncValueStr(const char *xml_path, std::string &value, const char *init_value)
{
	const char* v = this->GetValueStr(xml_path);
	if (v) {
		value = v;
		return true;
	}

	return this->SetValueStr(xml_path, init_value);
}

bool XmlHandler::Save(const char *_save_file)
{
	std::string save_file = filename_;
	if (_save_file) {
		save_file = _save_file;
	}

	std::ofstream fs(save_file);
	if (!fs.is_open()) {
		this->MakeLastError(StringFormat("cannot open save file: %s", save_file.c_str()));
		return false;
	}

	fs << doc_;
	if (!fs) {
		this->MakeLastError(StringFormat("cannot save file: %s", save_file.c_str()));
		return false;
	}

	return true;
}

void XmlHandler::MakeLastError(const std::string &error_info)
{
	lasterror_ = "XmlHandler Error, ";
	lasterror_ += "File: " + filename_ + ", ";
	lasterror_ += error_info;
}
