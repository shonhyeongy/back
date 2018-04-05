//
//  main.cpp
//  C++home
//
//  Created by 손현기 on 2018. 4. 3..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include <cstdio>

class Stack{
public:
    int *data;
    int top ;
public:

    Stack(){
        data = new int[255];
        top = 0;
    }

    void push (double tdata){
        data[top++] = tdata;
    }
    void setter (){
        top = 0;
    }
    int get (int i){
        return data[i];
    }
    
    void display(){
        int s=0;
        while (1) {
            if (s>top-1) {
                break;
            }
            else{
                printf("%d\n",data[s]);
                s++;
            }
        }
    }

};

int func(int a){
    int data = sqrt(a);
    int count = 2;
    int check =0;
    
    while (1) {
        if (data < count) {
            break;
        }
        else{
            if (a%count==0) {
                check = -1;
                break;
            }
            count++;
        }
    }
    return check;
}



///Users/sonhyeongi/Desktop/school2/C++/C++home/C++home/

int main(int argc, const char * argv[]) {
    
  //  printf("Start!!!\n");
    
    std::fstream inStream;
    int Numtestcase;
    

    inStream.open("input.txt");
    if (inStream.fail()) {
        printf("NONO");
    }
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    int bigger_x = 0;
    int bigger_y =0;
    
    
    inStream >> Numtestcase;
    
    for (int i =0; i<Numtestcase; i++) {
        inStream >> x1 >>y1 >>x2 >>y2 >> x3 >> y3 >>x4 >> y4;
        Stack s = Stack();
        s.push(x1);
        s.push(x2);
        s.push(x3);
        s.push(x4);
        for (int i=0; i<4; i++) {
            int data = s.get(i);
            if (bigger_x < data) {
                bigger_x = data;
            }
        }
        s.setter();
        s.push(y1);
        s.push(y2);
        s.push(y3);
        s.push(y4);
        
        for (int i=0; i<4; i++) {
            int data = s.get(i);
            if (bigger_y < data) {
                bigger_y = data;
            }
        }
        
        char set[bigger_y][bigger_x];
        
        if (x1==x2) {
            if (y1>y2) {
                for (int i1 = y2; i1<y1+1; i1++) {
                    set[x1][i1] = 1;
                }
            }
            else if (y1<y2){
                
            }
        }
        else if (y1==y2){
            
        }
        
        
        
        
        
 
        
        

    }
    return 0;
    
}
