#pragma once

#include "FrameType.hpp"

class TenthFrame : public FrameType
{
private:
    std::tuple<int, int, int> tries;
    std::pair<int, int> tmp;
    int try1;
    int try2;
    int try3;

public:
    TenthFrame(int try1, int try2, int try3) : try1(try1), try2(try2), try3(try3)
    {
        setFrameTrie();
    }
    void setFrameTrie() override
    {
        tries = std::make_tuple(try1, try2, try3);
    }
    std::pair<int, int> &getNormalTries() override
    { // ony used to define virtual func
        tmp = std::make_pair(-1, -1);
        return tmp;
    }
    std::tuple<int, int, int> &getTenthTries() override
    {
        return tries;
    }
};
