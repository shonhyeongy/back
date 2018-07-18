//c++ BattleShip 프로젝트
//작성 일자 : 2018-06-02
//학번 : 20171636 이름 : 손현기


#pragma once

#include "StatPane.h"
#include "InputPane.h"
#include "BattleShipMap.h"
#include <iostream>
using namespace std;

class CBattleShipApp {
public:

    void play(int time);

protected:
    void Init();

    void Render();

    void Destroy();

    int autoplay(string data,int count1, int count2 , int count3);

protected:
    CBattleShipMap *m_pMap;
    CBattleShipMap *m_pMap2;
    CBattleShipMap *m_pMap3;
    StatPane *m_pStatPane;
    InputPane *m_pInputPane;
};
