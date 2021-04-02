#include <ctime>
#include "colorprintf/colorprintf.hpp"

#define DEBUG_LOG(format, ...)\
do {\
    time_t now = time(nullptr); \
    struct tm *tmp_now = localtime(&now); \
    char date[1024]; \
    strftime(date, 1024, "%Y-%m-%d %H:%M:%S", tmp_now); \
    colorprintf(1, "[%s] " format "\n", date, ##__VA_ARGS__); \
    fflush(stdout); \
} while (0)

#define WARNING_LOG(format, ...)\
do {\
    time_t now = time(nullptr); \
    struct tm *tmp_now = localtime(&now); \
    char date[1024]; \
    strftime(date, 1024, "%Y-%m-%d %H:%M:%S", tmp_now); \
    colorprintf(2, "[%s] " format "\n", date, ##__VA_ARGS__); \
    fflush(stdout); \
} while (0)

#define ERROR_LOG(format, ...)\
do {\
    time_t now = time(nullptr); \
    struct tm *tmp_now = localtime(&now); \
    char date[1024]; \
    strftime(date, 1024, "%Y-%m-%d %H:%M:%S", tmp_now); \
    colorprintf(0, "[%s] " format "\n", date, ##__VA_ARGS__); \
    fflush(stdout); \
} while (0)
