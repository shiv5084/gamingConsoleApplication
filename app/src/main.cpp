#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include "BowlingGame.hpp"

using namespace std;

int main()
{

    BowlingGame player(10);

    player.getInput(player);

    int totalFinalScore = player.CalculateTotalScore();
    cout << totalFinalScore;

    return 0;
}
