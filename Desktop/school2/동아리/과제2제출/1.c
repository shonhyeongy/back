#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    
    int input;
    
    int *data;
    int *data1;
    
    scanf("%d",&input);
    
    data = malloc(sizeof(int)*5);  // 5개의 공간
    
    data = realloc(data, 7);// 2개를 추가
    
    data1 = calloc(sizeof(int),5); // 5개의 공간 0으로 초기화
    
    
    
    
    
    free(data);
    return 0;
}
