//
//  main.c
//  과제_2
//
//  Created by 손현기 on 2018. 3. 26..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <stdio.h>

typedef struct STACK{
    int Array_Stack [100];
    int pop;
} STACK;


void push(int *s , int *pop1, int data){
    int *p = pop1;
    if (*p>99) {
        printf("FULL");
    }
    else{
        s[*p]=data;
        *p = *p +1;
    }
}
void display_data(int *s, int *pop){
    int count =0;
    int *p = pop;
    while (count !=*p) {
        printf("%d\n",s[count]);
        count++;
    }
}
int peek(int *s, int *pop){
    int *p = pop;
    int result = s[*p-1];
    printf("peek() is %d\n",result);
    return result;
}

int pop(int *s, int *pop){
    int *p = pop;
    int result = s[*p-1];
    printf("pop() is %d\n",result);
    *p = *p - 1;
    return result;
    
}


int main(int argc, const char * argv[]) {
    
    struct STACK a;
    a.pop = 0;
    
    for (int i =0; i<10; i++) {
        push(a.Array_Stack, &a.pop, i);
    }
    display_data(a.Array_Stack, &a.pop);
    peek(a.Array_Stack, &a.pop);
    pop(a.Array_Stack, &a.pop);
    display_data(a.Array_Stack, &a.pop);
    
    
    return 0;
}
