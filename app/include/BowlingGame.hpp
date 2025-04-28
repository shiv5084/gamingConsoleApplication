#pragma once

#include "FrameType.hpp"
#include "FrameFactory.hpp"
#include "NormalFrame.hpp"
#include "TenthFrame.hpp"
#include "utility.hpp"


class BowlingGame
{
private:
    int numOfFrame;
    BonusType Btype;
    int currentTotalScore;
    int totalTriescore;
    std::vector<FrameType *> frame;

public:
    BowlingGame(int num) : numOfFrame(num), currentTotalScore(0),totalTriescore(0), Btype(NOBONUS) {}
    ~BowlingGame(){}
   
    void shutDown()
    {
        for (auto fr : frame)
        {
            delete fr;
        }
        frame.clear();
    }

    std::vector<FrameType *> &getframe()
    {
        return frame;
    }

    void getInput(BowlingGame &bg);
    int CalculateTotalScore();
};
