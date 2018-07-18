//c++ BattleShip 프로젝트
//작성 일자 : 2018-06-02
//학번 : 20171636 이름 : 손현기


#include <iostream>
#include <cstdlib>
#include <string>

#ifndef BATTLE_AI_AUTOSELECT_H
#define BATTLE_AI_AUTOSELECT_H

class Auto{

public:
    char State_Check[8][8];
    char x,y;
    char origin_x, origin_y;
    int dir[4];
    int count;
    int total_count;

public:

    Auto(char data[][8]){
        getMap(data);
        x=0;
        y=0;
        origin_x =0;
        origin_y =0;
        count=0;
        total_count = 0;
    }


    std::string select(char data[][8]);
    char get_position();
    bool check_boundary(int x, int y,char data[][8]);
    void getMap(char data[][8]);


    std::string turning(char data[][8]);
    void find_dir();
    std::string change(int x, int y,  std::string &data);
    char operator() (unsigned int idx);

    std::string go(char data[][8]);
    std::string back(char data[][8]);






};







#endif //BATTLE_AI_AUTOSELECT_H
