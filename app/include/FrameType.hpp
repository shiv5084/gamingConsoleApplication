#pragma once

#include <iostream>
#include <bits/stdc++.h>


class FrameType
{
    int framescore;

public:
    FrameType() : framescore(0) {}

    virtual void setFrameTrie() = 0;
    virtual std::pair<int, int> &getNormalTries() = 0;
    virtual std::tuple<int, int, int> &getTenthTries() = 0;
    void setFrameScore(int score)
    {
        framescore = score;
    }
    virtual ~FrameType() = default;
};
