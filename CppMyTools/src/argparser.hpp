#pragma once

#include <map>
#include <string>

// ֧�����������ʽ����������
// program -opt1 value1 -opt2 -opt3 value3 ����Ϊ map { {"opt1", "value1"}, {"opt2", ""}, {"opt3", "value3"} }
// ���������޸� argv �ڵ��ַ���
void parse_args(int argc, char* argv[], std::map<std::string, std::string>& result);