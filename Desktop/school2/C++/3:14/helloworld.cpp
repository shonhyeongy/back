#include <iostream>
using namespace std;
#define st "Hello world"
#define MY_MAX(X,Y) ((X>Y)? (X) : (Y))

int main(){


	
	int my_max = MY_MAX(1,5);
	printf("%d",my_max);
	int i = 3;
	cout << "hello world" << endl;

	#ifdef _DEBUG_
	cout << "i= "<< i << endl;	
	#endif

	return 0; 
}
