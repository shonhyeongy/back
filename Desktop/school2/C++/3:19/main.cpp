#include <iostream>
#include <climits>
int main(){

	char c = 'a';
	int i ;
//	char cl =UCHAR_MAX;
//	i =(int) c;

	i = static_cast<int>(c);
	
	unsigned char cl = std::numeric_limits<unsigned char>::max();

	std::cout << c << std::endl;
	std::cout << i << std::endl;
//	std::cout <<static_cast<int>(cl) << std::endl;
	std::cout << static_cast<int>(cl) << std::endl;
	return 0;


}
