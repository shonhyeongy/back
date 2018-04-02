#include <stdio.h>

int sum (int a, int b);

int sum(int a, int b){
	int result = 0;
	result = a + b;

	return result;

}

int fac(int a);

int fac(int a){

	if(a==1){
		return 1;
	}
	else{
		return a*fac(a-1);
}

}




int main(void){

int a;

printf("Hello World!\n");


a = fac(5);

printf("%d",a);




return 1;
}
