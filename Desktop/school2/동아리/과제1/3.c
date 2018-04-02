#include <stdio.h>

int main(void) {

    int input=5;
    int count1;
    int count2;
 
    
    for (count1=2; count1<input; count1++) {
        for (count2=1; count2<6; count2++) {
            printf("%d * %d = %d",count1,count2,count1*count2);
            
        }
        printf("\n");
    }
    
    
    return 0;
}

