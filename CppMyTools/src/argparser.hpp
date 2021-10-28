#pragma once

#include <map>
#include <string>

// 支持命令参数格式（举例）：
// program -opt1 value1 -opt2 -opt3 value3 解析为 map { {"opt1", "value1"}, {"opt2", ""}, {"opt3", "value3"} }
// 函数不会修改 argv 内的字符串
void parse_args(int argc, char* argv[], std::map<std::string, std::string>& result);