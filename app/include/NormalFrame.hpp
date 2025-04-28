#pragma once

#include "FrameType.hpp"

class NormalFrame : public FrameType
{
private:
    std::pair<int, int> tries;
    std::tuple<int, int, int> tmp;
    int try1;
    int try2;

public:
    NormalFrame(int try1, int try2) : try1(try1), try2(try2)
    {
        setFrameTrie();
    }
    void setFrameTrie() override
    {
        tries = std::make_pair(try1, try2);
    }
    std::pair<int, int> &getNormalTries() override
    {
        return tries;
    }
    std::tuple<int, int, int> &getTenthTries() override
    { // ony used to define virtual func
        tmp = std::make_tuple(-1, -1, -1);
        return tmp;
    }
};

