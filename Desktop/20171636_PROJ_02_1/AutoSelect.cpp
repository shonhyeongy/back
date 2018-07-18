//
// Created by sonhyeongi on 6/6/18.
//

#include "AutoSelect.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
std::string Auto::select(char data[][8]) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);

    x = rand()%8;
    y = rand()%8;
    std::string result;
    if(check_boundary(x,y,data)){
        std::stringstream ss;
        std::string s;
        char x1 = 65+x;
        ss << x1;
        ss >> s;
        result +=s;
        char y1 = '1'+y;
        result +=y1;
        origin_x = x;
        origin_y = y;
    }
    else{
        result = "!";
    }
    return result;

}

std::string Auto::go(char data[][8]) {
    int direction = dir[count];
    int new_x = x;
    int new_y = y;
    std::string result;
    if (direction==0){
        new_y +=1;
    }
    else if (direction==1){
        new_y -=1;
    }
    else if (direction==2){
        new_x +=1;
    }
    else if (direction==3){
        new_x -=1;
    }

    if(check_boundary(new_x ,new_y,data)){
        std::stringstream ss;
        std::string s;
        char x1 = 65 + new_x;
        ss << x1;
        ss >> s;
        result +=s;
        char y1 = '1'+new_y;
        result +=y1;
        x = new_x;
        y = new_y;
    }
    else{
        result = "!";
    }

    return result;
}

std::string Auto::back(char data[][8]){
    int direction = dir[count];
    char new_x = origin_x;
    char new_y = origin_y;
    std::string result;
    if (direction==0){
        new_y -=1;
    }
    else if (direction==1){
        new_y +=1;
    }
    else if (direction==2){
        new_x -=1;
    }
    else if (direction==3){
        new_x +=1;
    }

    if(check_boundary(new_x ,new_y,data)){
        std::stringstream ss;
        std::string s;
        char x1 = 65 + new_x;
        ss << x1;
        ss >> s;
        result +=s;
        char y1 = '1'+new_y;
        result +=y1;
        origin_x = new_x;
        origin_y = new_y;
    }
    else{
        result = "!";
    }

    return result;

}

//동 0 서 1 남  2 북 3

void Auto::find_dir() {
    if(x<=3 && y<=3){      //  2
        dir[0] = 2;
        dir[1] = 1;
        dir[2] = 3;
        dir[3] = 0;
    }
    else if (x<=3 && y>=3){  // 1
        dir[0] = 2;
        dir[1] = 0;
        dir[2] = 3;
        dir[3] = 1;
    }
    else if (x>=3 && y<=3){ // 3
        dir[0] = 3;
        dir[1] = 0;
        dir[2] = 1;
        dir[3] = 2;
    }
    else if (x>=3 && y>=3){  // 4
        dir[0] = 3;
        dir[1] = 1;
        dir[2] = 2;
        dir[3] = 0;
    }
}

//동 0 서 1 남  2 북 3

std::string Auto::turning(char data[][8]) {

    int direction = dir[count];
    int new_x = x;
    int new_y = y;
    std::string result;

    if (direction==0){
        new_y +=1;
    }
    else if (direction==1){
        new_y -=1;
    }
    else if (direction==2){
        new_x +=1;
    }
    else if (direction==3){
        new_x -=1;
    }

    if(check_boundary(new_x ,new_y, data)){
        std::stringstream ss;
        std::string s;
        char x1 = 65+new_x;
        ss << x1;
        ss >> s;
        result +=s;
        char y1 = '1'+new_y;
        result +=y1;
        x = new_x;
        y = new_y;
    }
    else{
        result = "!";
    }

    return result;

}


bool Auto::check_boundary(int x, int y , char data[][8]) {
    bool flag = false;
    if ((x>=0 && x<=7) && (y>=0 && y<=7)){
        if(data[x][y]!='H' && data[x][y]!='M'){
            flag = true;
        }
    }
    return flag;
}

void Auto::getMap(char data[][8]){
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            State_Check[i][j] = data[i][j];
        }
    }
}