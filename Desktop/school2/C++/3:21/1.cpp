#include <iostream>
#include <fstream>

int main(){

	int	numTestCases;
	
	std::ifstream	inFile;

	inFile.open("input.txt");
	
	if (inFile.fail()){
	printf("NONO");
	}

	inFile >> numTestCases;

	std::cout << numTestCases << std::endl;
	
	inFile.close();
	return 0;

}
