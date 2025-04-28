#include "BowlingGame.hpp"
#include "FrameFactory.hpp"
#include "FrameType.hpp"
#include "NormalFrame.hpp"
#include "TenthFrame.hpp"
// #include "utility.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class FrameFactoryTest : public ::testing::Test
{
protected:
    FrameFactoryTest() : bg(10)
    {
        std::cout << "FrameFactoryTest()\n";
    }

    ~FrameFactoryTest()
    {
        std::cout << "~FrameFactoryTest()\n";
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

//Create Normal Frame Test
TEST_F(FrameFactoryTest, TestCreateNormalFrame){
    FrameFactory::createFrame(bg,"NORMAL", 2, 4);
    ASSERT_EQ(bg.getframe().size(), 1);
    auto* frame = dynamic_cast<NormalFrame*>(bg.getframe()[0]);
    ASSERT_NE(frame , nullptr);

    auto [first,second] = frame->getNormalTries();
    EXPECT_EQ(first,2);
    EXPECT_EQ(second,4);
    
    auto [t1,t2,t3] = frame->getTenthTries();
    EXPECT_EQ(t1,-1);
    EXPECT_EQ(t2,-1);
    EXPECT_EQ(t3,-1);
}

//Create TENTH Frame Test
TEST_F(FrameFactoryTest, TestCreateTenthFrame){
    FrameFactory::createFrame(bg,"TENTH", 2, 4);
    ASSERT_EQ(bg.getframe().size(), 1);
    auto* frame = dynamic_cast<TenthFrame*>(bg.getframe()[0]);
    ASSERT_NE(frame , nullptr);

    auto [first,second] = frame->getNormalTries();
    EXPECT_EQ(first,-1);
    EXPECT_EQ(second,-1);
    
    auto [t1,t2,t3] = frame->getTenthTries();
    EXPECT_EQ(t1,2);
    EXPECT_EQ(t2,4);
    EXPECT_EQ(t3,0);
}

//invalid Frame Test
TEST_F(FrameFactoryTest, TestCreateInvalidFrame){
    EXPECT_THROW(FrameFactory::createFrame(bg,"UNLNOWN", 2, 4),std::invalid_argument);
    ASSERT_EQ(bg.getframe().size(), 0);
}

//Create Frames with all try values 10 Test 
TEST_F(FrameFactoryTest, TestCreateAllFramesWithPinValue10){
    for(int i=0;i<9;i++){
        FrameFactory::createFrame(bg,"NORMAL", 10, 10);
    }
    FrameFactory::createFrame(bg,"TENTH", 10, 10, 10);
    ASSERT_EQ(bg.getframe().size(), 10);
}

//Create Frames with all try values 0 Test 
TEST_F(FrameFactoryTest, TestCreateAllFramesWithPinValue0){
    for(int i=0;i<9;i++){
        FrameFactory::createFrame(bg,"NORMAL", 0, 0);
    }
    FrameFactory::createFrame(bg,"TENTH", 0, 0, 0);
    ASSERT_EQ(bg.getframe().size(), 10);
}


