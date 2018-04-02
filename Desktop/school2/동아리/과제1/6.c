#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#define  BUFF_SIZE   5

int main(void) {

    char Data1[255] = "Hellow";
    char Data2[255] = "I'm";
    char Data3[255] = " age";
    char Data4[255];
    char Data5[255];
    int a = 20;
    
   
  
    
    char     buff[BUFF_SIZE];

    ssize_t  rd_size;
    
    
    printf("%s\n", Data1);
    
    strcpy(Data1,"Hellow hyeongi");
    printf("%s\n", Data1);
    
    sprintf(Data1, "%s %s %d",Data1, Data2, a);
    printf("%s\n",Data1);
    
    strcat(Data1, Data3);
    printf("%s\n", Data1);
    
    gets(Data4);
    puts(Data4);
    
   
    int fd = open("/Users/sonhyeongi/Test/Test/test.txt", O_RDWR);
    
    char data[255] = "hello";
    char real_data[255] ;
    read(fd, &real_data, 1);
    
    write(fd, &data, 20);
    
    printf("%s\n",real_data);
   

    
    
    
    return 0;
}
