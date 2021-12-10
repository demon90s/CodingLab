#include "hhmm.hpp"
#include <iostream>

int main()
{
    int hhmm = 0;
    std::cout << "input hhmm: ";
    while (std::cin >> hhmm)
    {
        if (IsValidHHMM(hhmm))
        {
            int hour = 0;
            int min = 0;
            ParseHHMM(hhmm, hour, min);

            std::cout << "hour is: " << hour << std::endl;
            std::cout << "min  is: " << min << std::endl; 
        }
        else
        {
            std::cout << "Invalid HHMM" << std::endl;
        }

        std::cout << "input hhmm: ";
    }
}