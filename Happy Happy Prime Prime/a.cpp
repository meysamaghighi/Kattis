// Meysam Aghighi
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> happy(10001,false);
vector<bool> mark(10001,false);

bool prime(int n){
    if (n==1) return false;
    if (n==2) return true;
    for (int i=2;i<=sqrt(n);i++) if (n%i==0) return false;
    return true;
}

bool solve(int n){
    // cerr << n << endl;
    if (mark[n]) return happy[n];
    int s = 0, nn = n; // s = sum of squared digits
    while(nn) s+=(nn%10)*(nn%10), nn/=10;
    if (s == 1){
        mark[n] = true;
        return happy[n] = true;
    }
    mark[n] = true;
    bool temp = solve(s);
    // mark[n] = true;
    return happy[n] = temp;
}

int main(){    
    mark[1] = true;
    happy[1] = true;
    int n,t,i;
    cin >> t;
    while (t--){
        cin >> i >> n;
        cout << i << " " << n;
        if (solve(n) && prime(n)) cout << " YES\n";
        else cout << " NO\n";
    }
    return 0;
}