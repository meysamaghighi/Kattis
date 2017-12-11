//Meysam Aghighi
// EZ!
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    assert(n>=1 && n<=10000);
    cout << ceil(log2(n))+1 << endl;
    return 0;
}
