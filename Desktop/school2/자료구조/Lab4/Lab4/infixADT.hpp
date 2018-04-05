//
//  infixADT.hpp
//  Lab4
//
//  Created by 손현기 on 2018. 4. 4..
//  Copyright © 2018년 손현기. All rights reserved.
//

#ifndef infixADT_hpp
#define infixADT_hpp

#include <stdio.h>

class stack_data{
    
public:
    char arraystack[100];
    int top =0;
public:
    void push(char data);
    char pop();
    char pop2();
    
    int Empty();
    int Full();
    void display();
    int getter();
    
};



#endif /* infixADT_hpp */
