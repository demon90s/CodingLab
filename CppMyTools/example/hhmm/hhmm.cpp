#include "hhmm.hpp"

void ParseHHMM(int hhmm, int &hour, int &min)
{
    hour = hhmm / 100;
    min = hhmm % 100;
}

bool IsValidHHMM(int hhmm)
{
    int hour = 0, min = 0;

    ParseHHMM(hhmm, hour, min);

    return hour >= 0 && hour < 24 && min >= 0 && min < 60;
}
