#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    long double t;
    cin >> n;
    if (n%4!=0 && n%2==0){
        cout << "impossible" << endl;
        return 0;
    }
    if (n%4==0){
        cout << (n/2-2)/2 << " " << (n/2+2)/2 << endl;
        return 0;
    }
//    for (int i=1;i<n/2;i++){
//        if (n%i==0){
//            cout << (n/i-i)/2 << " " << (n/i+i)/2 << endl;
//            return 0;
//        }
//    }
    cout << (n-1)/2 << " " << (n+1)/2 << endl; 
//    cout << "impossible" << endl;
    return 0;
}

