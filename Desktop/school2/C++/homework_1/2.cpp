i
#include <iostream>
#include<fstream>
#include<cstdlib>
using namespace std;


int main(void){
ifstream inStream;
    int numTestCases;

inStream.open("input.txt");
    if(inStream.fail())
    {

	printf("ddd");
        exit(1);
    }

    inStream >> numTestCases;
for (int i = 0; i < numTestCases; i++)
    {
	int a;
	int b;
	int result =0;
	inStream >> a >> b;
	for (int i2 =a; i2 < b+1; i2++){
	
	result = result + i2;
	}
	cout << result << endl;






	
    }


	inStream.close();
	return 0;

}
