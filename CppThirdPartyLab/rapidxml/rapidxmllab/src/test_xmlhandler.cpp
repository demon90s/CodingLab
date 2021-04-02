#include "test_xmlhandler.h"
#include "xmlhandler.h"
#include <iostream>

namespace
{
    void test1()
    {
        XmlHandler xh;
        /*
        {
            const char* name = xh.GetValueStr("config/name");
            if (!name) {
                std::cerr << xh.ErrorDesc() << std::endl;
                return;
            }
        }
        */

        if (!xh.Parse("test.xml")) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }

        /*
        if (!xh.GetValueStr("config")) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }
        */

        const char* name = xh.GetValueStr("config/name");
        if (name) {
            std::cout << "got name: " << name << std::endl;
        }
        else {
            std::cerr << xh.ErrorDesc() << std::endl;
        }

        const char *age = xh.GetValueStr("config/age");
        if (age) {
            std::cout << "got age: " << age << std::endl;
        }

        const char *number = xh.GetValueStr("config/phone/number");
        if (number) {
            std::cout << "got number: " << number << std::endl;
        }
    }

    void test2()
    {
        XmlHandler xh("test3.xml");
        if (!xh.Parse()) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }

        if (!xh.SetValueStr("config/test/data", "qqqq")) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }

        const char* bbb = "bbbbbbbb";
        if (!xh.SetValueStr("config/test/bbbb", bbb)) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }

        if (!xh.SetValueStr("config/test/far", "42")) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }

        if (!xh.Save()) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }
    }

    void test3()
    {
        XmlHandler xh("test3.xml");
        if (!xh.Parse()) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }

        std::string tmp = "tmp";
        if (!xh.SyncValueStr("config/test/data", tmp, tmp.c_str())) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }
        else {
            std::cout << "got data: " << tmp << std::endl;
        }

        std::string PI;
        if (!xh.SyncValueStr("config/math/pi", PI, "3.14")) {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }
        else {
            std::cout << "got PI: " << PI << std::endl;
        }

        xh.Save();
    }

    void test4()
    {
        XmlHandler xh;
        if (!xh.Parse("test4.xml"))
        {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }

        XmlNode numbers_node = xh.GetNode("config/numbers");
        if (!numbers_node)
        {
            std::cerr << xh.ErrorDesc() << std::endl;
            return;
        }

        XmlNode data_node = numbers_node.GetFirstChild("data");
        while (data_node)
        {
            std::string name;
            long long number = 0;

            if (data_node.GetSubNodeValue("name", name) &&
                data_node.GetSubNodeValue("number", number))
            {
                std::cout << name << " - " << number << std::endl;
            }

            data_node = data_node.GetNextSibling();
        }
    }
}

void test_XmlHandler()
{
   // test1();
    //test2();
    //test3();
    test4();
}
