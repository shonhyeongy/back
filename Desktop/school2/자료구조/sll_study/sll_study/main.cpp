//
//  main.cpp
//  sll_study
//
//  Created by 손현기 on 2018. 4. 2..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

typedef struct NODE{
    int data;
    char Name;
    char ID;
    char Major;
    
    NODE *next;
}NODE;

typedef class linkedlist{
public:
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

class que{
private:
    int count =0;
    int data[5];
    int fin=-1;
    int start=-1;
    
public:
    void push(int tdata){
        
        start = (start + 1 )%5;
        if (start==fin) {
            printf("FULL\n");
        }
        else{
            data[start] = tdata;
            count++;
        }
        
    }
    int display(){
        fin = (fin + 1)%5;
        if (start==fin or count==0) {
            printf("Empty\n");
        }
        else{
            count--;
            return data[fin];
        }
        return NULL;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    
    linkedlist *L = (linkedlist *)malloc(sizeof(linkedlist));
    L->head = NULL;
    L->tail = NULL;
    
    L->push(L, 1);
    L->push(L, 2);
    L->push(L, 3);
    L->push(L, 4);
    
    que q;
    q.display();
    
    
    L->display(L);
   
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
