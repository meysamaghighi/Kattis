#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,a;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a;
        cout << (long long)pow(2,a)-1 << endl;
    }
    return 0;
}