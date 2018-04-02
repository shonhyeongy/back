
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void)
{
    ifstream inStream;
    int numTestCases;
    
    
    ///Users/sonhyeongi/Desktop/school2/111/111/
    
    inStream.open("input.txt");
    if(inStream.fail())
    {
        cerr<<"Input file opening failed.\n";
        exit(1);
    }
    
    char data[255][255];
    inStream>>numTestCases;
    
    int h=0;
    int middle=0;
    int start_p;
    int start_s;
    int count = 1;
    
    for (int i=0; i<numTestCases; i++){
        inStream>>h;
        middle = h/2;
        count=1;
        for (int i1 =0 ; i1<h; i1++) {
            for (int i2=0; i2<h; i2++) {
                data[i1][i2] = '-';
            }
        }
        for (int i3 =0 ; i3<h; i3++) {
            start_p=i3+1;
            start_s=i3;
            if (i3<middle+1) {
                for (int i4=0; i4<h; i4++) {
                    if (i3%2==0) {
                        if (i4%2==1) {
                            if (start_p==h-i3) {
                                break;
                            }
                            data[i3][start_p]='+';
                            start_p = start_p + 2;
                        }
                        else{
                            if (start_s==h-i3) {
                                break;
                            }
                            data[i3][start_s]='*';
                            start_s = start_s + 2;
                        }
                        
                    }
                    else{
                        if (i4%2==0) {
                            if (start_p==h-i3) {
                                data[i3][start_s]='*';
                                break;
                            }
                            data[i3][start_p]='+';
                            start_p = start_p + 2;
                        }
                        else{
                            if (start_s==h-i3) {
                                
                                break;
                            }
                            data[i3][start_s]='*';
                            start_s = start_s + 2;
                        }
                    }
                }
            }
            
            
            else{
                start_s =h/2-count;
                start_p =h/2-count+1;
                int o_s = start_s;
                int o_p = start_p;
                
                
                for (int i4=0; i4<h; i4++) {
                    if (i3%2==0) {
                        if (i4%2==1) {
                            if (start_p==o_p+count*2) {
                                break;
                            }
                            data[i3][start_p]='+';
                            start_p = start_p + 2;
                        }
                        else{
                            if (start_s==o_s+count*2) {
                                data[i3][start_s]='*';
                                break;
                            }
                            data[i3][start_s]='*';
                            start_s = start_s + 2;
                        }
                        
                    }
                    else{
                        if (i4%2==0) {
                            if (start_p==o_p+count*2) {
                                data[i3][start_s]='*';
                                break;
                            }
                            data[i3][start_p]='+';
                            start_p = start_p + 2;
                        }
                        else{
                            if (start_s==o_s+count*2) {
                                break;
                            }
                            data[i3][start_s]='*';
                            start_s = start_s + 2;
                        }
                    }
                }
                count++;
            }
        }
        for (int a1 =0; a1<h; a1++) {
            for (int b1=0; b1<h; b1++) {
                printf("%c",data[a1][b1]);
            }
            printf("\n");
        }
        
    }
    return 0;
}




