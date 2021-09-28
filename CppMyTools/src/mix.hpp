#pragma once

#include <fstream>

// 获取数组x的长度
#define NELEMS(x) ((sizeof(x)) / (sizeof((x)[0])))

std::streamoff stream_size(std::istream& f);