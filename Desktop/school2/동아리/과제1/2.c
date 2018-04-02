#include <stdio.h>

int main(void) {

    int input=0;
    
    int total=0;
    
    int count =0;
    float average=0;
    while (1) {
        
        scanf("%d",&input);
        if (input>100) {
        
            break;
        }
        else{
            total = total + input;
            count = count + 1;
        }
    }
    printf("%d",total);
    printf("\n");
    average = (double)total/count;
    average = average + 0.05;
    printf("%.1f",average);
    
    return 0;
}

