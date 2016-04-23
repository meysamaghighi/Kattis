#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

using namespace std;

int main(){
    bitset <64> a,b;
    int x;
    cin >> x;
    a = (bitset <64>) x;
    b = a;
    //cout << a << endl;
    //cout << a[0] << endl;
    //cout << a[60] << endl;
    int n = ceil(log2(x));
    if ((x & (x - 1)) == 0)
        n++;
    //cout << n << endl;
    for (int i=0;i<n;i++)
        b.set(i,a[n-i-1]);
    //cout << b << endl;
    cout << b.to_ulong() << endl;
    return 0;
}
