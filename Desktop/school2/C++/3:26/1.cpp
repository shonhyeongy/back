#include <iostream>

// function signature == function name + input parameter types;


int sum (int a, int b=1){

	int result = a + b;

	return result;
}

int sum (int a){
	
	


	int result = a;

	return a;


}

int pp(){

	static float f = 3.4f;
	
	f = f + 1.0;

	std::cout << f << std::endl;

	return 0;

}

int pp2(){

	static float f ;

	f = 3.4f;

	f = f + 1.0;

	std::cout << f << std::endl;

	return 0 ;

}




int main(void){

	std:: cout << "ddd" << std::endl;	


	
	pp2();
	pp2();

	return 0;

}
