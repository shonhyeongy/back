//
//  main.cpp
//  C++test
//
//  Created by 손현기 on 2018. 3. 28..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>
#include<fstream>
#include <cstdlib>

int main() {
    
    std::ifstream inStream;
    int numTestCases;
    //   /Users/sonhyeongi/Desktop/school2/C++/C++test/C++test/
    inStream.open("/Users/sonhyeongi/Desktop/school2/C++/C++test/C++test/input.txt");
    if(inStream.fail())
    {
        
        printf("ddd");
        exit(1);
    }
    
    inStream >> numTestCases;
    
    int count1= 0;
    int data;
    
    
  
    
  
    //int result_data = 0;
    
   
    int bigger_1=0;
    int bigger_2=0;
    
    for (int i=0; i<numTestCases; i ++) {
        inStream >> count1;
        bigger_2 =0;
        bigger_1 = 0;
        for (int i1=0; i1<count1; i1++) {
            inStream >> data;
            if (bigger_1 < data) {
                bigger_2 = bigger_1;
                bigger_1 = data;
                
                
            }
        }
        if (bigger_2==0) {
            printf("%d\n",bigger_1);
        }
        else{
            printf("%d\n",bigger_2);
        }
        
        
    }
        
        
        
    

    return 0;
}

