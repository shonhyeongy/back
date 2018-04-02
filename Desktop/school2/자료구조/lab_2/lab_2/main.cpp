#include <iostream>
using namespace std;

int fibo(int a){
    if (a==0){
        return 0;
    }
    else if (a==1){
        return 1;
    }
    else{
        return (fibo(a-1)+fibo(a-2));
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int num =0;
    
    scanf("%d",&num);
    
    
    int p = fibo(num);
    
    printf("%d\n",p);
    return 0;
}
