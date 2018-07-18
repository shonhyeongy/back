//
//  main.cpp
//  Random
//
//  Created by 손현기 on 2018. 5. 28..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "BattleShipApp.h"

using namespace std;




int main(int argc, const char *argv[]) {


    CBattleShipApp battleShipApp;
    battleShipApp.play(1); //시간 설정
                            // 1일때면 늦지만 공격하는거 다 볼수있음
                            //0.5일땐 빠르지만 공격하는거 순식간에 지나감


    std::cout << "Hello, World!\n";
    return 0;
}
