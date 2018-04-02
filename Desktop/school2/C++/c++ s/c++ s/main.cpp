//
//  main.cpp
//  c++ s
//
//  Created by 손현기 on 2018. 3. 12..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>
using namespace std;

class A{
private:
        int *row;
        int *col;
        int *value;
        int error = 0;
public:
    A (int *a , int *b, int *c){
        row = a;
        col = b;
        value = c;
    }
    
    void setter(){
    }
    int* getter(string check){
        if (check == "row"){
            return row;
        }
        else if (check == "col"){
            return col;
        }
        else if (check == "value"){
            return value;
        }
        
        return &error;
    }
};

class Poly{
public:
    int *expon;
    float *coef;
    
    Poly(int *a , float *b){
        expon = a;
        coef = b;
    }
};

int sum (Poly a, Poly b, int size_a , int size_b);

int sum (Poly a, Poly b, int size_a , int size_b){
    
    int check_a =0;
    int check_b =0;
    
    int result[255];
    int count =0;
    
    
    while (1) {
        
        if (check_a==size_a && check_b==size_b) {
            break;
        }
        else{
            
            if (a.expon[check_a]>b.expon[check_b]) {
                result[count] = a.expon[check_a];
                count ++;
                result[count] = a.coef[check_a];
                count ++;
                check_a++;
               
            }
            else if (a.expon[check_a]<b.expon[check_b]){
                result[count] = b.expon[check_b];
                count ++;
                result[count] = b.coef[check_b];
                count ++;
                check_b++;
                
            }
            else if (a.expon[check_a]==b.expon[check_b]){
                result[count] = b.expon[check_b];
                count ++;
                result[count] = b.coef[check_b] + a.coef[check_a];
                count ++;
                check_a++;
                check_b++;
                
            }
            
            
        }
    }
    for (int start=0; start < 30 ; start++) {
        
        std:: cout << result[start] << std::endl;
        
    }
    
    return 0;
}






int trans (A a_m,int size);

int trans (A a_m,int size){
    int trans_row[255];
    int trans_col[255];
    int trans_value[255];
    
    int MAX_COL = a_m.getter("col")[0];
    int Value_count = a_m.getter("value")[0];
    
    
    int col_count[MAX_COL];
    int start_pos[255];
    
    for (int count =0; count<MAX_COL; count++) {
        col_count[count] = 0;
    }
    for (int count =1; count<size; count++){
        int check = a_m.getter("col")[count];
        
        col_count[check]++;

    }
    start_pos[0]=1;
    for (int count=1; count<MAX_COL; count++) {
        start_pos[count] = start_pos[count-1] + col_count[count-1];
        
       // printf("%d\n", col_count[count-1] );
    }
    
    for (int i =1; i<=Value_count; i++){
        int j = start_pos[a_m.getter("col")[i]]++;
        trans_row[j] = a_m.getter("col")[i];
        trans_col[j] = a_m.getter("row")[i];
        trans_value[j] = a_m.getter("value")[i];
    }
    
    for (int i=1; i<=Value_count; i++) {
        std:: cout << trans_row[i] <<" "<< trans_col[i]<< " "<< trans_value[i]<<  " "<< std::endl;
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
//    int a1[] = {6,4,2,1,0};   // x^6 + 3x^4 + 4x^2 + 3x + 1
//    float a2[] = {1,3,4,2,1};
//
//    int b1[] = {3,1,0};  // 8x^3 + 5x + 2
//    float b2[] = {8,5,2};                                  // 6 1 4 3 3 8 2 4 1 7 0 3
//
//    int size_a = sizeof(a1)/sizeof(int);
//    int size_b = sizeof(b1)/sizeof(int);
//
//
//    Poly a_1 = {a1,a2};
//    Poly b_1 = {b1,b2};
//
//    sum(a_1, b_1,size_a,size_b);
    
    
    
    int a1_row[] = {6,0,0,0,1,1,2,4,5};
    int a2_col[] = {6,0,3,5,1,2,3,0,2};
    int a3_value[] = {8,15,22,-15,11,3,-6,91,28};
    
    int matrix_size = sizeof(a1_row)/sizeof(int);
    
    A a_matrix = {a1_row,a2_col,a3_value};
    
    trans(a_matrix, matrix_size);
    
    
    
    
    
    

    
    
    return 0;
}
