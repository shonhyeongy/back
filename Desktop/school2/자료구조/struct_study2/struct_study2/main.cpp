//
//  main.cpp
//  struct_study2
//
//  Created by 손현기 on 2018. 3. 27..
//  Copyright © 2018년 손현기. All rights reserved.
//
#include <iostream>
#include <fstream>


class stack{
private:
    char data[255];
    int top;
public:
    void push(char mdata){
        data[top++] = mdata;
    }
    char pop(){
        int a = top -1;
        top--;
        return data[a];
    }
    int getter(){
        return top;
    }
    void setter(int data){
        top = data;
    }
    
};

int main(int argc, const char * argv[]) {
    
    char input[255];
   // int check[255];
    
   
    
    std::ifstream inStream;
    int numTestCases;
    
    inStream.open("/Users/sonhyeongi/Desktop/school2/자료구조/struct_study2/struct_study2/input.txt");
    if(inStream.fail())
    {
        
        printf("ddd");
        exit(1);
    }
    
    inStream >> numTestCases;
    
    stack s;
    char a ;
    int check = 0;
    int check2=0;
    
    for (int i =0; i<numTestCases; i++) {
        check = 0;
        check2 = 0;
        inStream >> input;
        unsigned long size = strlen(input);
        for (int i2 =0; i2<size; i2++) {
            if(input[i2]=='('||input[i2]=='{'||input[i2]=='['){
                s.push(input[i2]);
            }
            else if(input[i2]==')'){
                if (s.getter()<0) {
                    check2=1;
                    s.setter(0);
                    break;
                }
                a = s.pop();
                if (a!='(') {
                    if (a==NULL) {
                        printf("Unbalanced rigth parentheses are more than left parentheses\n");
                        //s.setter(0);
                        break;
                    }
                    printf("Mismatched parentheses are %c , %c\n",input[i2],a);
                    check =1;
                    s.setter(0);
                    break;
                }
            }
            else if(input[i2]=='}'){
                if (s.getter()<0) {
                    check2=1;
                    s.setter(0);
                    break;
                }
                a = s.pop();
                if (a==NULL) {
                    printf("Unbalanced rigth parentheses are more than left parentheses\n");
                   // s.setter(0);
                    break;
                }
                if (a!='{') {
                    printf("Mismatched parentheses are %c , %c\n",input[i2],a);
                    check =1;
                    s.setter(0);
                    break;
                }
                
            }
            else if(input[i2]==']'){
                if (s.getter()<0) {
                    check2=1;
                    s.setter(0);
                    break;
                }
                a = s.pop();
                if (a==NULL) {
                    printf("Unbalanced rigth parentheses are more than left parentheses\n");
                  //  s.setter(0);
                    break;
                }
                if (a!='[') {
                    printf("Mismatched parentheses are %c , %c\n",input[i2],a);
                    check =1;
                    s.setter(0);
                    break;
                }
            }
            
            
            
        }
        if (check !=1) {
            int size2 = s.getter();
            if (size2==0) {
                if (check2==1) {
                    printf("Unbalanced rigth parentheses are more than left parentheses\n");
                    s.setter(0);
                }
                printf("Balanced\n");
                s.setter(0);
                
            }
            else if (size2>=1){
                printf("Unbalanced Left parentheses are more than right parentheses\n");
                s.setter(0);
            }
        }
        
        
    }
    
    
//    for (int i=0; i<numTestCases; i++) {
//        printf("%d\n",check[i]);
//    }

    
    
    
    
    // insert code here...
    return 0;
}
