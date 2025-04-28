#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include "FrameFactory.hpp"

using namespace std;

void FrameFactory::createFrame(BowlingGame &bg, const string &type, int try1, int try2, int try3)
{
    if (type == "NORMAL")
    {
        bg.getframe().emplace_back(new NormalFrame(try1, try2));
    }
    else if (type == "TENTH")
    {
        bg.getframe().emplace_back(new TenthFrame(try1, try2, try3));
    }
    else
    {
        throw std::invalid_argument("invalid frame type");
    }
}
