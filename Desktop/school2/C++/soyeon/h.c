#include <stdio.h>

int main(void){

int a =0;
int check =0;

printf("a\t b\t c\t d\t e\t f\t g\t \n");

for (a=1; a<32; a++ ){
	if (check==7){

		check=1;
		printf("\n");
		printf("%d\t ",a);
}
else{
	printf("%d\t ",a);
	check ++;

}


}


return 0;
}
