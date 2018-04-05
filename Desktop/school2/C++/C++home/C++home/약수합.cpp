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
    int a;
    
    inStream >> Numtestcase;
    
    for (int i =0; i<Numtestcase; i++) {
        inStream >> a;
        
        Stack s = Stack();
        Stack s2 = Stack();
        
        int origin = a;
        int result = 1;
        int start = 2;
        int count = 0;
        
        while (1) {
            count = 0;
            result = 1;
            if (a==1) {
                break;
            }
            else{
                if (func(a)==0) {
                    s.push(2);
                    s2.push(1 + a);
                    break;
                }
                else{
                    if (func(start)==0) {
                        if (a%start==0) {
                            while (1) {
                                if (a%start!=0) {
                                    s.push(count+1);
                                    s2.push(result);
                                    break;
                                }
                                else{
                                    a = a/start;
                                    count++;
                                    result = result + pow(start, count);
                                }
                            }
                        }
                        else{
                            start++;
                        }
                    }
                    else{
                        start++;
                    }
                }
            }
            
            
            
        }
        
        int left = 1;
        int right = 1;
        
        //s.display();
    //    s2.display();
        
        for (int t=0; t<s.top; t++) {
            left = left*s.get(t);
        }
        for (int t=0; t<s2.top; t++) {
            right = right*s2.get(t);
        }
        printf("%d %d\n",left-1,right-origin);
        
        
        
        s.setter();
        s2.setter();
        
        
 
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
    return 0;
    
}
