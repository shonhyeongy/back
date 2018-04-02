#include <stdio.h>

int main(void) {

    int input=0;
    int count1;
    int count2;
    
    scanf("%d",&input);
    
    for (count1=0; count1<input+1; count1++) {
        for (count2=0; count2<count1; count2++) {
            printf("*");
        }
        printf("\n");
    }
    
    
    return 0;
}

