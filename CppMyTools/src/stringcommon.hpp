#pragma once

#include <string>
#include <vector>

namespace stringcommon
{

std::string &Trim(std::string &str);

std::string Format(const char *fmt, ...);

std::vector<std::string> Split(const std::string &str, const char *delim);

// 从路径中抓取到文件的名字： /root/home/diwen/hello.txt -> hello.txt
std::string FetchNameFromPath(const std::string &path, const char *delim = "/");

}
