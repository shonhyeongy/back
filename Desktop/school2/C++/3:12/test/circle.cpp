#include <iostream>
#include "circle.h"
using namespace std;

int main(){
    double perimeter, area ,radius;
    
    radius = 1.0;
    perimeter = calc_perimeter(radius);
    area = calc_area(radius);
    
    cout << "perimeter=" <<perimeter << endl;
    cout << "area=" <<area << endl;

    return 0;
}
