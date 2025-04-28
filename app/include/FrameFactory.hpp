#pragma once

#include "FrameType.hpp"
#include "BowlingGame.hpp"
#include "NormalFrame.hpp"
#include "TenthFrame.hpp"

class BowlingGame;  //forward declare for BowlingGame &bg

class FrameFactory
{
public:
    static void createFrame(BowlingGame &bg, const std::string &type, int try1, int try2, int try3 = 0);
};
