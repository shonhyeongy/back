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

for (int i=0; i <numTestCases; i++){

int a, b;

inStream >> a >> b;

int sum, min, min_p, mult, dev, ret, big , equl;

sum = a + b;
min = a - b;
if (min<0){
min_p = 0 - min;
}
else{
min_p = min;
}
mult = a*b;
dev = a/b;
ret = a%b;
if (a>b){
big = a;
}else{
big = b;
}
if (a==b){
equl = 1;
}
else{
equl = 0;
}

cout << sum <<" "<< min<<" "<<min_p<<" "<<mult<<" "<<dev<<" "<<ret<<" "<<big<<" "<<equl << endl;
}
return 0;




}
