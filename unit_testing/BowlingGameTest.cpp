// #pragma once
#include <algorithm>
#include "BowlingGame.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


class BowlingGameTest : public ::testing::Test
{
protected:
    BowlingGameTest() : bg(10)
    {
        std::cout << "BowlingGameTest()\n";
    }

    ~BowlingGameTest()
    {
        std::cout << "~BowlingGameTest()\n";
    }

    void SetUp() override
    {
        std::cout << "setup\n";
    }

    void TearDown() override
    {
        std::cout << "TearDown\n";
        bg.shutDown();
    }

    BowlingGame bg;
};


TEST_F(BowlingGameTest, Testgetframe)
{
    FrameFactory::createFrame(bg, "NORMAL", 10, 10);
    FrameFactory::createFrame(bg, "TENTH", 10, 10);
    ASSERT_EQ(bg.getframe().size(), 2);
}

// logic test for CalculateTotalScore

// when frame number(frame[i]) < 9 && i<7 (frame number < 8) && first == 10 && frame[i+1] == 10
TEST_F(BowlingGameTest, TestCalculateTotalScore1)
{
    FrameFactory::createFrame(bg, "NORMAL", 10, 0);
    FrameFactory::createFrame(bg, "NORMAL", 10, 0);

    for (int i = 2; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 30);
}

// when frame number(frame[i]) < 9 && i< 7 (frame number < 8) && first == 10 && frame[i+1] != 10
TEST_F(BowlingGameTest, TestCalculateTotalScore2)
{
    FrameFactory::createFrame(bg, "NORMAL", 10, 0);

    for (int i = 1; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);

    EXPECT_EQ(bg.CalculateTotalScore(), 10);
}

// when frame number(frame[i]) < 9 && i==7 (frame number == 8) && first == 10 && frame[i+1] == 10
TEST_F(BowlingGameTest, TestCalculateTotalScore3)
{
    for (int i = 0; i < 7; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "NORMAL", 10, 0);
    FrameFactory::createFrame(bg, "NORMAL", 10, 0);
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 30);
}

// when frame number(frame[i]) < 9 && i==7 (frame number == 8) && first == 10 && frame[i+1] != 10
TEST_F(BowlingGameTest, TestCalculateTotalScore4)
{
    for (int i = 0; i < 7; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "NORMAL", 10, 0);
    FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 10);
}

// when frame number(frame[i]) < 9 && i==8 (frame number == 9) && first == 10 && frame[i+1] == 10
TEST_F(BowlingGameTest, TestCalculateTotalScore5)
{
    for (int i = 0; i < 8; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "NORMAL", 10, 0);
    FrameFactory::createFrame(bg, "TENTH", 10, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 30);
}

// when frame number(frame[i]) < 9 && i==8 (frame number == 9) && first == 10 && frame[i+1] != 10
TEST_F(BowlingGameTest, TestCalculateTotalScore6)
{
    for (int i = 0; i < 8; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "NORMAL", 10, 0);
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 10);
}

// when frame number(frame[i]) < 9 && i< 9 && i != 8 && first + second == 10
TEST_F(BowlingGameTest, TestCalculateTotalScore7)
{
    FrameFactory::createFrame(bg, "NORMAL", 6, 4);
    for (int i = 1; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 10);
}

// when frame number(frame[i]) < 9 && i == 8 (frame number == 9) && first + second == 10
TEST_F(BowlingGameTest, TestCalculateTotalScore8)
{
    for (int i = 0; i < 8; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "NORMAL", 6, 4);
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 10);
}

// when frame number(frame[i]) < 9
TEST_F(BowlingGameTest, TestCalculateTotalScore9)
{
    FrameFactory::createFrame(bg, "NORMAL", 3, 5);
    for (int i = 1; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 8);
}

// when frame number(frame[i]) == 9(frame number == 10) && t1 == 10
TEST_F(BowlingGameTest, TestCalculateTotalScore10)
{
    for (int i = 0; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "TENTH", 10, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 10);
}

// when frame number(frame[i]) == 9(frame number == 10) && t1 + t2 == 10
TEST_F(BowlingGameTest, TestCalculateTotalScore11)
{
    for (int i = 0; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "TENTH", 6, 4, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 10);
}

// when frame number(frame[i]) == 9(frame number == 10)
TEST_F(BowlingGameTest, TestCalculateTotalScore12)
{
    for (int i = 0; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "TENTH", 2, 3, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 5);
}

// edge cases
// when all frame value 10
TEST_F(BowlingGameTest, TestCalculateTotalScoreAllFrame10)
{
    for (int i = 0; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 10, 10);
    }
    FrameFactory::createFrame(bg, "TENTH", 10, 10, 10);
    EXPECT_EQ(bg.CalculateTotalScore(), 290);
}

// when all frame value 0
TEST_F(BowlingGameTest, TestCalculateTotalScoreAllFrame0)
{
    for (int i = 0; i < 9; i++)
    {
        FrameFactory::createFrame(bg, "NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg, "TENTH", 0, 0, 0);
    EXPECT_EQ(bg.CalculateTotalScore(), 0);
}
//testing getInput
TEST_F(BowlingGameTest, TestgetInput1)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "10\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput2)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "5\n5\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput3)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "5\n6\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput4)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "-2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput5)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "11\n6\n0\n\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput6)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n10\n0\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput7)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n4\n3\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput8)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n6\n4\n8\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput9)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2\n4\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 10);
}

TEST_F(BowlingGameTest, TestgetInput10)
{
    std::streambuf* origCin = std::cin.rdbuf();
    std::string inputData = "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n8\n8\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
    std::istringstream input(inputData); 
    std::cin.rdbuf(input.rdbuf());
    bg.getInput(bg);
    std::cin.rdbuf(origCin);
    EXPECT_EQ(bg.getframe().size(), 19);
}
