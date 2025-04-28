#pragma once

#include <iostream>
#include <bits/stdc++.h>


inline int getValidatedInput(const std::string &stream, int min = 0, int max = 10)
{
    int val;
    while (1)
    {
        std::cout << stream;
        std::cin >> val;
        if (val < min || val > max)
        {
            std::cerr << "invalid input, try again\n";
        }
        else
        {
            break;
        }
    }
    
    return val;
}

enum BonusType
{
    NOBONUS = 0,
    SPARE,
    STRIKE,
};

