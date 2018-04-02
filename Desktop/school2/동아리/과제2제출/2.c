//
//  main.c
//  과제2
//
//  Created by 손현기 on 2018. 3. 21..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
    struct NODE *cur;
    struct NODE *head;
    struct NODE *tail;
} linkedlist;

typedef struct NODE{
    int data;
    struct NODE *next;
} NODE;

void push(linkedlist *L, int tdata);


void push(linkedlist *L, int tdata){
    
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode -> data = tdata;
    newNode -> next = NULL;
    if (L-> head == NULL && L->tail == NULL) {
        L->head = L ->tail = newNode;
    }
    else{
        L->tail->next = newNode;
        L->tail = newNode;
    }
}
void myrm(linkedlist *L, int rdata);

void myrm(linkedlist *L, int rdata){
    NODE *p1 = L->head;
    NODE *p2 = p1->next;
    NODE *p3 = p2;
    int check =0;
    
    while (p2->next!= NULL) {
        if (p1->data==rdata) {
            NODE *p4 = p1;
            p1 = p1->next;
            L ->head = p1;
            free(p4);
            p2 = p2->next;
            p3 = p2;
        }
        else{
            if (p2->data==rdata) {
                
                p1->next = p2->next;
                p2 = p2->next;
                
                free(p3);
                p3 = p2;
                check = 1;
            }
            else{
                p1 = p1->next;
                p2 = p2->next;
                p3 = p2;
            }
        }
        
    }
    if (p2->data==rdata) {
        L->tail = p1;
        p1->next = NULL;
        free(p2);
        p2 = NULL;
        
    }
    
    if (check == 0) {
        printf("No your number!\n");
    }
    
}

int popdata(linkedlist *L);

int popdata(linkedlist *L){
    
    NODE *p = L -> tail;
    NODE *p1 = L -> head;
    while (p1->next->next !=NULL) {
        p1 = p1 ->next;
    }
    L -> tail = p1;
    p1 -> next = NULL;
    int result = p->data;
    free(p);
    p = NULL;
    
    
    
    
    return result;
    
}
void printNodes(linkedlist *L);

void printNodes(linkedlist *L){
    NODE *p = L -> head;
    putchar('[');
    while (p != NULL) {
        printf("%d, ", p->data);
        p = p ->next;
    }
    putchar(']');
    putchar('\n');
}


int main(int argc, const char * argv[]) {
    
    
    linkedlist *L = (linkedlist *)malloc(sizeof(linkedlist));
    L ->cur = NULL;
    L ->head = NULL;
    L ->tail = NULL;
    
    push(L, 3);
    push(L, 3);
    push(L, 3);
    push(L, 3);
    push(L, 1);
    push(L, 3);
    push(L, 3);
    push(L, 3);
    push(L, 5);
    push(L, 3);
    push(L, 3);
    push(L, 3);
    push(L, 3);
    push(L, 4);
   
    
    myrm(L, 3);
    int a = popdata(L);
    
    printf("%d\n",a);
    printNodes(L);
    
    
    
    
    
    
    
    
    
    
    
    
    struct NODE *head = malloc(sizeof(struct NODE));
    
    struct NODE *node1 = malloc(sizeof(struct NODE));

    struct NODE *node2 = malloc(sizeof(struct NODE));
    
    struct NODE *node3 = malloc(sizeof(struct NODE));
    
    node1 -> data = 30;
    node2 -> data = 20;
    node3 -> data = 10;
    
    head -> next = node3;
    node3 -> next = node2;
    node2 -> next = node1;
    node1 -> next = NULL;
    
    struct NODE * curr = head->next;
    while (curr !=NULL) {
        printf("%d\n", curr->data);
        curr = curr ->next;
    }
    
    free(node2);
    free(node1);
    free(head);
    
    
    
    
    return 0;
}
