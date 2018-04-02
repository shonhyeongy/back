//
//  main.cpp
//  C++ Lab2_test
//
//  Created by 손현기 on 2018. 3. 21..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class info{
private:
    double *triangle;
    double *rectangle;
    double *circle;
    int a;
    int b;
    int c1;
    
    char *input_name;
    double *value;

public:
    info(char *name , double *v){
        input_name = name;
        value = v;
        
        
        
        
//        triangle = t;
//        rectangle = r;
//        circle = c;
//        a = size_t;
//        b = size_r;
//        c1 = size_c;
//
        
        
        
    }
public:
    
//    void function(){
//        int t[255];
//        int r[255];
//        int c[255];
//
//        double result;
//
//        for (int i =0; i <a; i++) {
//
//        result = triangle[i] * triangle[i*2 -1];
//
//        printf("%lf \n",triangle[i]);
//
//
//        printf("%lf , %lf \n",triangle[i],triangle[i+1]);
//
//
//
//        }
//
//        for (int i =0; i <b; i++) {
//            result = rectangle[i] * rectangle[i+1];
//            r[i] = result;
//        }
//
//        for (int i =0; i < c1; i++) {
//            result = circle[i] * circle[i] * 3.14;
//            c[i] = result;
//        }
////
////        for (int i =0; i< a; i++) {
////            cout << "triangle" <<" " << triangle[i] << " " << triangle[i+1] << " " << t[i] << endl;
////        }
//
//
//
//
//
//
//    }
//
    void function(){
        double result[255];
        int count = 0;
        for (int i = 0; i< 10; i++) {
            if (input_name[i]=='t') {
                result[i] = (value[count] * value[count+1])/2;
                count++;
                count++;
            }
            else if (input_name[i]=='r') {
                result[i] = value[count] * value[count+1];
                count++;
                count++;
            }
            else if (input_name[i]=='c') {
                result[i] = value[count] * value[count] * 3.14;
                count++;
            }
        }
    
        int count2= 0;
        for (int i = 0; i<7; i++) {
            if (input_name[i]=='t') {
                printf("triangle %.2f %.2f %.2f\n",value[count2],value[count2+1],result[i]);
                count2 ++;
                count2 ++;
            }
            else if (input_name[i]=='r') {
                printf("rectangle %.2f %.2f %.2f\n",value[count2],value[count2+1],result[i]);
                count2 ++;
                count2 ++;
                
            }
            else if (input_name[i]=='c') {
                printf("circle %.2f %.2f\n",value[count2],result[i]);
                count2 ++;
               
                
            }
        }
        
        
    }
    
    
    
    
};

int main(int argc, const char * argv[]) {
    
    ifstream inStream;
    int numTestCases;
    
    char check_name[255] ;
    double num1;
    double num2;
    
    char name_data[255];
    double value_data[255];
    int total = 0;
    
    inStream.open("/Users/sonhyeongi/Desktop/school2/자료구조/C++ Lab2_test/C++ Lab2_test/Lab2.txt");
    if(inStream.fail())
    {
        
        printf("ddd");
        exit(1);
    }
    
    numTestCases = 7;
    
    for (int i = 0; i<numTestCases; i++) {
        
        inStream >> check_name;
        
        //printf("%s\n",check_name);
        
        if (strncmp(check_name,"triangle",8)==false) {
            inStream  >> num1 >> num2;
            
       //     printf("%lf, %lf\n",num1,num2);
            
//            t[t_c] = num1;
//            t_c ++;
//            t[t_c] = num2;
//            t_c ++;
//
            name_data[i] = 't';
            value_data[total] = num1;
            value_data[total+1] = num2;
            total++;
            total++;
            
            
            
        }
        else if (strncmp(check_name,"rectangle" , 9)==false) {
            inStream  >> num1 >> num2;
            
            //printf("%lf, %lf\n",num1,num2);
//            r[r_c] = num1;
//            r_c ++;
//            r[r_c] = num2;
//            r_c ++;
            
            name_data[i] = 'r';
            value_data[total] = num1;
            value_data[total+1] = num2;
            total++;
            total++;
            
            
            
        }
        else if (strncmp(check_name,"circle" , 6)==false) {
            inStream  >> num1;
            
            //printf("%lf\n",num1);
            
//            c[c_c] = num1;
//            c_c++;
           
            name_data[i] = 'c';
            value_data[total] = num1;
            total++;
           
            
            
        }
        
    }
    
    info a1 = {name_data,value_data};
    a1.function();
 
    
    
    
    
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
    

}





















