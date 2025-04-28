#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include "BowlingGame.hpp"

using namespace std;

void BowlingGame::getInput(BowlingGame &bg)
{
    try
    {
        for (int i = 1; i <= 9; ++i)
        {
            int try1, try2;
            cout << "Frame " << i << ":\n";
            try1 = getValidatedInput("Enter the number of pins knocked down in 1st try:\n");

            // If strike, 2nd try is 0
            if (try1 == 10)
            {
                try2 = 0;
            }
            else
            {
                try2 = getValidatedInput("Enter the number of pins knocked down in 2nd try:\n");
            }

            if (try1 + try2 > 10)
            {
                throw invalid_argument("Sum of tries cannot exceed 10 in a single frame!");
            }

            FrameFactory::createFrame(bg, "NORMAL", try1, try2);
        }

        // Tenth frame
        int try1, try2, try3 = 0;
        cout << "Frame 10:\n";
        try1 = getValidatedInput("Enter the number of pins knocked down in 1st try: \n");
        // If strike, 2nd try is 0
        if (try1 == 10)
        {
            try2 = 0;
        }
        else
        {
            try2 = getValidatedInput("Enter the number of pins knocked down in 2nd try: \n");
        }

        if (try1 + try2 > 10)
        {
            throw invalid_argument("Sum of tries cannot exceed 10 in a single frame!\n");
        }

        if (try1 == 10 || try1 + try2 == 10)
        {
            try3 = getValidatedInput("Bonus! Enter the number of pins knocked down in Bonus try: \n");
        }

        FrameFactory::createFrame(bg, "TENTH", try1, try2, try3);
    }
    catch (const invalid_argument &e)
    {
        cerr << "input error" << e.what() << endl;
        getInput(bg); // re-prompt
    }
}

int BowlingGame::CalculateTotalScore()
{
    for (int i = 0; i < frame.size(); i++)
    {
        if (i < 9)
        {
            auto [first, second] = frame[i]->getNormalTries();
            if (first == 10)
            {
                Btype = STRIKE;
                if (i < 7)
                {
                    auto [next1, next2] = frame[i + 1]->getNormalTries();
                    if (next1 == 10)
                    {
                        currentTotalScore = first + next1 + frame[i + 2]->getNormalTries().first;
                        totalTriescore = totalTriescore + currentTotalScore;
                    }
                    else
                    {
                        currentTotalScore = first + next1 + next2;
                        totalTriescore = totalTriescore + currentTotalScore;
                    }
                }
                else if (i == 7)
                {
                    auto [next1, next2] = frame[i + 1]->getNormalTries();
                    if (next1 == 10)
                    {
                        currentTotalScore = first + next1 + get<0>(frame[i + 2]->getTenthTries());
                        totalTriescore = totalTriescore + currentTotalScore;
                    }
                    else
                    {
                        currentTotalScore = first + next1 + next2;
                        totalTriescore = totalTriescore + currentTotalScore;
                    }
                }
                else
                {
                    auto [t1, t2, t3] = frame[i + 1]->getTenthTries();
                    if (t1 == 10)
                    {
                        currentTotalScore = first + t1 + t3;
                        totalTriescore = totalTriescore + currentTotalScore;
                    }
                    else
                    {
                        currentTotalScore = first + t1 + t2;
                        totalTriescore = totalTriescore + currentTotalScore;
                    }
                }
            }
            else if ((first + second) == 10)
            {
                Btype = SPARE;
                if (i != 8)
                {
                    currentTotalScore = first + second + frame[i + 1]->getNormalTries().first;
                    totalTriescore = totalTriescore + currentTotalScore;
                }
                else
                {
                    currentTotalScore = first + second + get<0>(frame[i + 1]->getTenthTries());
                    totalTriescore = totalTriescore + currentTotalScore;
                }
            }
            else
            {
                Btype = NOBONUS;
                currentTotalScore = first + second;
                totalTriescore = totalTriescore + currentTotalScore;
            }
        }
        else
        {
            auto [t1, t2, t3] = frame[i]->getTenthTries();
            if (t1 == 10)
            {
                currentTotalScore = t1 + t3;
                totalTriescore = totalTriescore + currentTotalScore;
            }
            else if ((t1 + t2) == 10)
            {
                currentTotalScore = t1 + t2 + t3;
                totalTriescore = totalTriescore + currentTotalScore;
            }
            else
            {
                currentTotalScore = t1 + t2;
                totalTriescore = totalTriescore + currentTotalScore;
            }
        }
        frame[i]->setFrameScore(totalTriescore);
    }
    return totalTriescore;
}
