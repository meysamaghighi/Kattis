// Meysam Aghighi
#include <iostream>
#include <cmath>
using namespace std;

int divisor_sum(int n){
    int ans = 1, nn = sqrt(n);
    for (int i=2;i<sqrt(n);i++) if (n%i == 0) ans += i + n/i;
    if (nn*nn == n) ans += nn;
    return ans;
}

int main(){
    int n;
    while (cin >> n){
        int t = divisor_sum(n);
        if (t == n) cout << n << " perfect\n";
        else if (t >= n-2 && t <= n+2) cout << n << " almost perfect\n";
        else cout << n << " not perfect\n";
    }
    return 0;
}