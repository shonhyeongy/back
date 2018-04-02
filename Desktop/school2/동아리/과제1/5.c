#include <stdio.h>

int main(void) {

    int input;
    int result=1;
    int count;
    
    scanf("%d",&input);
    
    for (count=0; count<input; count++) {
        result = result *2;
    }
    printf("%d",result);
    
    return 0;
}

