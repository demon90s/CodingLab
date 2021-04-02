#include <cstdlib>

#include <iostream>
#include <string>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"

using namespace std;

namespace
{
	void ParsingTest()
	{
		using namespace rapidxml;
		file<> text("test.xml");
		// 注意：
		// 1. file 的内容如果提前销毁，doc 则无法再使用，二者绑定在一起
		// 2. 如果文件不存在，file 的构造函数会抛出异常
		xml_document<> doc; // character type defaults to char

		try
		{
			doc.parse<0>(text.data()); // 0 means default parse flags
		}
		catch (parse_error e)
		{
			cout << "Parsing file fail: " << e.what() << endl;
			return;
		}

		cout << "Parsing file succ" << endl;
	}

	void AccessingTest()
	{
		using namespace rapidxml;
		file<> text("test.xml");
		xml_document<> doc; // character type defaults to char

		try
		{
			doc.parse<0>(text.data()); // 0 means default parse flags
		}
		catch (parse_error e)
		{
			cout << "Parsing file fail: " << e.what() << endl;
			return;
		}

		// Accessing The DOM Tree
		cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
		xml_node<>* node = doc.first_node()->first_node("foobar");
		cout << "Node foobar has value: " << node->value() << "\n";
		for (xml_attribute<>* attr = node->first_attribute(); attr;
			attr = attr->next_attribute())
		{
			cout << "Node foobar has attribute " << attr->name() << " "
				<< "with value " << attr->value() << "\n";
		}
	}

	void ModifyingTest()
	{
		using namespace rapidxml;
		file<> text("test.xml");
		xml_document<> doc; // character type defaults to char

		try
		{
			doc.parse<0>(text.data()); // 0 means default parse flags
		}
		catch (parse_error e)
		{
			cout << "Parsing file fail: " << e.what() << endl;
			return;
		}

		xml_node<>* node = doc.allocate_node(node_element, "a", "Google");
		doc.append_node(node);
		xml_attribute<>* attr = doc.allocate_attribute("href", "google.com");
		node->append_attribute(attr);

		const char* name = "b";
		char* node_name = doc.allocate_string(name); // Allocate string and copy name into it
		// !VERY IMPORTANT! 字符串必须是动态内存，内部只保存指针，建议使用 allocate_string 分配
		xml_node<>* sub_node = doc.allocate_node(node_element, node_name, "111");
		node->append_node(sub_node);

		// Print to see
		cout << doc;
	}

	void PrintingTest()
	{
		using namespace rapidxml;
		file<> text("test.xml");
		xml_document<> doc; // character type defaults to char

		try
		{
			doc.parse<0>(text.data()); // 0 means default parse flags
		}
		catch (parse_error e)
		{
			cout << "Parsing file fail: " << e.what() << endl;
			return;
		}

		// Print to stream using operator <<
		std::cout << doc;

		// Print to stream using print function, specifying printing flags
		print(cout, doc, 0);

		// Print to string using output iterator
		string s;
		print(std::back_inserter(s), doc, 0);
		cout << s;

		// Save to file
		ofstream out("test_save.xml");
		out << doc;
	}
}

void rapidxml_example()
{
	// Tests

	ParsingTest();
	//AccessingTest();
	//PrintingTest();
	//ModifyingTest();

}
