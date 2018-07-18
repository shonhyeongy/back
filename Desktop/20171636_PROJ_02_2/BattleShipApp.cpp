#include "BattleShipApp.h"
#include "BattleShipMap.h"
#include <vector>
#include <string>
#include <unistd.h>
#include "AutoSelect.h"
using namespace std;

void CBattleShipApp::Init() {

    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(6, COLOR_BLACK, COLOR_BLACK);
    m_pMap = new CBattleShipMap("Defender");
    m_pMap2 = new CBattleShipMap("Attacker", 4, 16);
  //  m_pMap3 = new CBattleShipMap("Result", 4, 27);
    m_pStatPane = new StatPane(30, 3, 30, 10);
    m_pInputPane = new InputPane(30, 15, 30, 5);
}


// game is ing -> 1
// game is win -> 0
// battleship hit -> 2
// battleship miss -> 3

int CBattleShipApp::autoplay(string cmd,int count1 ,int count2 ,int count3) {
    int flag = 1;
    move(17, 40);
    const char* input = cmd.c_str();
    mvwprintw(m_pInputPane->m_pWindow,2,2, "Input : %s", input);

    //keypad(m_pInputPane->m_pWindow, false);
    //char cmd[2];
    //scanw("%s", cmd);
    //string scmd(cmd);
    if (cmd == "gg") {
        return 0;
    }

    m_pMap->Draw();

    if (m_pMap2->getFromCode(cmd) == '!') {
        mvwprintw(m_pInputPane->m_pWindow, 3, 2, "Result :BOUNDARY");
    } else if ((m_pMap2->getFromCode(cmd) == 'H') || (m_pMap2->getFromCode(cmd) == 'M')) {
        mvwprintw(m_pInputPane->m_pWindow, 3, 2, "Result : ALREADY");

    } else if (m_pMap->getFromCode(cmd) == '0') {
        m_pMap2->getFromCode(cmd) = 'M';
        wattron(m_pInputPane->m_pWindow, COLOR_PAIR(4));
        mvwprintw(m_pInputPane->m_pWindow, 3, 2, "Result : MISSED!"); // 변경사항
        wattron(m_pInputPane->m_pWindow, COLOR_PAIR(3));
        flag = 3;
       // ++count;
    } else {
        m_pMap2->getFromCode(cmd) = 'H';
        wattron(m_pInputPane->m_pWindow, COLOR_PAIR(1));
        mvwprintw(m_pInputPane->m_pWindow, 3, 2, "Result : SUCCESS"); // 변경사항
        wattron(m_pInputPane->m_pWindow, COLOR_PAIR(3));
        flag = 2;
       // ++count;
    }

    mvwprintw(m_pStatPane->m_pWindow, 5, 2, "Turn : %d", count1);
    mvwprintw(m_pStatPane->m_pWindow, 6, 2, "Total Turn : %d", count2);
    mvwprintw(m_pStatPane->m_pWindow, 7, 2, "Game count : %d", count3);
    mvwprintw(m_pStatPane->m_pWindow, 8, 2, "Average : %d", count2/count3);


    bool is_destroyed[] = {true, true, true, true}; // A,B,C,D 순서
    // 따로 배들의 좌표를 저장해놓는 자료구조를 안 만들어 놔서 화면에 H 이 체크된 것을 보고 모두 격추되었는지 is_destroyed 에 기록함
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (m_pMap->m_mapData[i][j] != '0' && m_pMap2->m_mapData[i][j] != 'H') {
                is_destroyed[m_pMap->m_mapData[i][j] - 65] = false;
            }
        }
    }
    m_pMap2->Draw();

//6.5day
//    for (int i = 0; i < 8; ++i) {
//        for (int j = 0; j < 8; ++j) {
//            if (m_pMap->m_mapData[i][j] != '0') {
//                if (m_pMap2->m_mapData[i][j] == 'H') {
//                    m_pMap3->m_mapData[i][j] = '0';
//                } else {
//                    m_pMap3->m_mapData[i][j] = '1';
//                }
//            }
//        }
//    }
//    m_pMap3->Draw();

    int x = 0;
    int j = 1;
    for (int k = 0; k < 4; ++k) {
        x = x | (is_destroyed[k] ? j : 0);
        j *= 2;
    }

    //m_pStatPane->Draw(1 | 4);
    m_pStatPane->Draw(x);

    wrefresh(m_pInputPane->m_pWindow); // 누적된 변경사항 화면에 표시

    int Game_clear = 0;
    for (int i = 0; i < 4; ++i) {
        if (is_destroyed[i] == true) {
            ++Game_clear;
        }
    }

    if (Game_clear == 4) {
        mvwprintw(m_pInputPane->m_pWindow, 3, 2, "Result : YOU WIN");
        m_pInputPane->Draw();
//        Destroy();
        flag=0;
    }
    return flag;
}

void CBattleShipApp::play(int time) {

    int total_count = 0;

    for (int i = 0; i <10 ; ++i) {
        Init();
        Render();
//    std::string data[10];
//    for (int i = 0; i <9 ; ++i) {
//        string a = "A";
//        char b = i+'0';
//        a += b;
//        data[i] = a;
//    }
        Auto a(m_pMap2->m_mapData);
        while (1) {
            int state;
            sleep(time);
            std::string input1 = a.select(m_pMap2->m_mapData);
            if (input1 == "!") {
                continue;
            }
            total_count++;
            a.total_count++;
            state = autoplay(input1, a.total_count , total_count , i+1);


            if (state == 0) {
                break;
            }
            else if (state == 2) {
                a.count = 0;
                std::string input2;
                std::string input3;
                std::string input4;
                int flag2;
                int flag3;
                int flag4;
                a.find_dir();
                while (1) {
                    if (a.count > 3) {
                        break;
                    }
                    input2 = a.turning(m_pMap2->m_mapData);
                    if (input2 == "!") {
                        a.count++;
                        continue;
                    }
                    sleep(1);
                    total_count++;
                    a.total_count++;
                    flag2 = autoplay(input2, a.total_count, total_count,  i+1);
                    if (flag2 == 2) {
                        break;
                    } else {
                        a.x = a.origin_x;
                        a.y = a.origin_y;
                        a.count++;
                    }
                }

                while (1) {
                    input3 = a.go(m_pMap2->m_mapData);
                    if (input3 == "!") {
                        break;
                    }
                    sleep(time);
                    total_count++;
                    a.total_count++;
                    flag3 = autoplay(input3, a.total_count,total_count , i+1);

                    if (flag3 == 3) {
                        break;
                    }
                }

                while (1) {
                    input4 = a.back(m_pMap2->m_mapData);
                    if (input4 == "!") {
                        break;
                    }
                    sleep(1);
                    total_count++;
                    a.total_count++;
                    flag4 = autoplay(input4, a.total_count,total_count , i+1);
                    if (flag4 == 3) {
                        break;
                    }
                }




//        a.getMap(m_pMap2->m_mapData);
//        if (a.State_Check[a.x][a.y]=='H'){
//            a.find_dir();
//            std::string input;
//
//
//
//        }
//
//        sleep(1);
            }
        }
    }
    Destroy();



}

void CBattleShipApp::Render() {
    mvprintw(1, 1, "<< Battle Ship Game >>");
    m_pMap->randomDeploy();
    m_pMap->Draw();
    m_pMap2->Draw();
  //  m_pMap3->Draw();
    m_pStatPane->Draw();
    m_pInputPane->Draw();

    refresh();
}

void CBattleShipApp::Destroy() {
    getch();
    endwin();
    delete m_pMap;
}


