#include <iostream>
#include <bits/stdc++.h>

using namespace std;

enum BonusType {
    NOBONUS=0,
    SPARE,
    STRIKE,
};

class Frame {
    private:
    tuple<int,int,int>  tries;
    int framescore;
    public:
    Frame(tuple<int,int,int> tp):framescore(0),tries(tp){}
    
    tuple<int,int,int> getTries(){
        return tries;
    }
    void setFrameScore(int score){
        framescore = score;
    }
};

class BowlingGame {
    private:
    int numOfFrame;
    BonusType Btype;
    int currentTotalScore;
    int prevTotalScore;
    int totalTriescore;
    vector<Frame> frame;
    public:
    BowlingGame(int num,initializer_list<tuple<int,int,int>> trilist):numOfFrame(num),currentTotalScore(0),prevTotalScore(0),Btype(NOBONUS){
        for(auto tp : trilist){
            frame.emplace_back(tp);
        }
    }
    
    int CalculateTotalScore(){
        for(int i=0;i<frame.size();i++){
            totalTriescore = get<0>(frame[i].getTries())+get<1>(frame[i].getTries());
            currentTotalScore = prevTotalScore+totalTriescore;
            if(get<0>(frame[i].getTries()) == 10 && i<9 ){
                Btype = STRIKE;
                currentTotalScore = currentTotalScore + get<0>(frame[i+1].getTries())+get<1>(frame[i+1].getTries());
            } else if(totalTriescore == 10 && i<9){
                Btype = SPARE;
                currentTotalScore = currentTotalScore + get<0>(frame[i+1].getTries());
            } else if(i==9) { 
                if(get<0>(frame[i].getTries()) == 10){
                Btype = STRIKE;
                currentTotalScore = currentTotalScore + get<2>(frame[i].getTries());
                prevTotalScore = currentTotalScore;
                } 
                if(totalTriescore == 10){
                    Btype = SPARE;
                    currentTotalScore = currentTotalScore + get<2>(frame[i].getTries());
                } 
            }
            frame[i].setFrameScore(currentTotalScore);
            prevTotalScore = currentTotalScore;
        }
        return currentTotalScore;
    }
};



int main()
{
    BowlingGame player ={10,{{1,4,0},{4,5,0},{6,4,0},{5,5,0},{10,0,0},{0,1,0},{7,3,0},{6,4,0},{10,0,0},{2,8,6}}};
    int totalFinalScore = player.CalculateTotalScore();
    cout<<totalFinalScore;

    return 0;
}
