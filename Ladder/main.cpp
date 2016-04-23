#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int h,v;
    cin >> h;
    cin >> v;
    
    int l = ceil((double)h/sin((double)v/90*M_PI_2));
    cout << l << endl;
    return 0;
}