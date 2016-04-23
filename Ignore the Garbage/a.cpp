// Meysam Aghighi

#include <iostream>
using namespace std;

int f(int n){
    // bring n to base 7
    // (0,1,2,3,4,5,6) to (0,1,2,5,6,8,9) then to (0,1,2,5,9,8,6)
    int x;
    while (n>0){
        x = n%7;
        n /= 7;
        if (x == 3) cout << 5;
        else if (x == 4) cout << 9;
        else if (x == 5) cout << 8;
        else cout << x;
    }
    cout << endl;
}

int main(){
    int n;
    while (cin>>n) f(n);
    return 0;
}
