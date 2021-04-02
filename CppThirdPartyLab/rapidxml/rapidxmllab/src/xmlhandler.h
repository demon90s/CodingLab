#pragma once

#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"

// ��װRapidXml�������õĲ���
// ͨ��һ��·����ʾxml�ڵ�, ���� "config/name" ���Ա�ʾ:
// <config>
// 		<name>Liudiwen</name>
// </config>

class XmlNode
{
	template<typename T>
	static bool StringToBaseType(const char* str, T& val)
	{
		std::istringstream iss(str);
		if (iss >> val) return true;
		else return false;
	}
public:
	XmlNode() : node_(nullptr)
	{

	}

	XmlNode(rapidxml::xml_node<>* node) : node_(node)
	{

	}

	const char* GetValue() const
	{
		return node_->value();
	}

	template<typename T>
	bool GetValue(T& value) const
	{
		const char* v = this->GetValue();
		if (nullptr == v || strlen(v) == 0)
		{
			return false;
		}

		return StringToBaseType(v, value);
	}

	const char* GetSubNodeValue(const char *subnode_name) const
	{
		XmlNode subnode = node_->first_node(subnode_name);
		if (subnode)
		{
			return subnode.GetValue();
		}
		return nullptr;
	}

	template<typename T>
	bool GetSubNodeValue(const char* subnode_name, T& value) const
	{
		const char* v = this->GetSubNodeValue(subnode_name);
		if (nullptr == v || strlen(v) == 0)
		{
			return false;
		}
		return StringToBaseType(v, value);
	}

	XmlNode GetFirstChild(const char* node_name = nullptr) const
	{
		return node_->first_node(node_name);
	}

	XmlNode GetNextSibling() const
	{
		return node_->next_sibling();
	}

	explicit operator bool() const
	{
		return nullptr != node_;
	}

private:
	rapidxml::xml_node<> *node_;
};

class XmlHandler
{
public:
	XmlHandler(const char* file_name = nullptr);
	~XmlHandler();
	XmlHandler(const XmlHandler&) = delete;
	XmlHandler& operator=(const XmlHandler&) = delete;

	bool Parse(const char *file_name = nullptr);

	const char* ErrorDesc() const {
		return lasterror_.c_str();
	}

	XmlNode GetNode(const char* xml_path) const;

	// ����xml��·����ȡֵ
	const char *GetValueStr(const char *xml_path) const;
	
	// ����xml��·������ֵ
	bool SetValueStr(const char *xml_path, const char *value);

	// ����xml��·��ͬ��ֵ, ���·��������, ��ôʹ�� init_value ��ʼ��
	bool SyncValueStr(const char *xml_path, std::string &value, const char *init_value);

	// �����ļ�
	bool Save(const char *save_file = nullptr);

private:
	void MakeLastError(const std::string &error_info);

	typedef rapidxml::xml_document<> XmlDoc;
	typedef rapidxml::file<> XmlFile;

	XmlDoc doc_;
	XmlFile *file_;
	std::string filename_;
	bool parsed_;
	std::string lasterror_;
};
