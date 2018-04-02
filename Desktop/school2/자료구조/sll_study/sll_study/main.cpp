//
//  main.cpp
//  sll_study
//
//  Created by 손현기 on 2018. 4. 2..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>

typedef struct NODE{
    int data;
    NODE *next;
}NODE;

typedef class linkedlist{
private:
    NODE *head;
    NODE *curr;
    NODE *tail;
public:
    void push(linkedlist *L , int mdata){
        NODE *newnode = (NODE*)malloc(sizeof(NODE));
        newnode ->data = mdata;
        newnode ->next = NULL;
        if (L->head==NULL && L->tail ==NULL) {
            L->head = newnode;
            L->tail = newnode;
        }
        else{
            L->tail->next = newnode;
            L->tail = newnode;
        }
    }
    
    void insert (linkedlist *L, int rdata){
        NODE *newnode = (NODE*)malloc(sizeof(NODE));
        newnode ->data = rdata;
        newnode ->next = NULL;
        
        
        
    }
    
    
    
    void display(linkedlist *L){
        NODE *p1 = L->head;
        while (1) {
            if (p1->next==NULL) {
                printf("%d\n",p1->data);
                break;
            }
            printf("%d\n",p1->data);
            p1=p1->next;
        }
        
    }
    
    
    
}linkedlist;



int main(int argc, const char * argv[]) {
    // insert code here...
    
    linkedlist *L = (linkedlist *)malloc(sizeof(linkedlist));
    L->push(L, 1);
    L->push(L, 2);
    L->push(L, 3);
    L->push(L, 4);
    L->display(L);
   
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
