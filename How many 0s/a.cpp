// Meysam Aghighi
#include <iostream>
using namespace std;

typedef long long ll;

ll g[12],gg[12]; // g[i] = number of zeros between 10^n and 10^{n+1}-1
void init(){
    g[0] = 1, gg[0] = 1;
    g[1] = 9, gg[1] = 10;
    for (int i=1;i<12;i++) g[i+1] = (i+1)*g[i]/i*10, gg[i+1] = gg[i] + g[i+1];
}

ll f(ll n){
    if (n<0) return 0;
    if (n==0) return 1;
    int d = 1, tn = n, a[12];
    a[0] = tn%10;
    while (tn>10) tn/=10, a[d++]=tn%10; // d = # of digits
}

int main(){
    init();
    for (int i=1;i<12;i++) cerr << g[i] << " " << gg[i] <<  endl;
    ll n,m;
    while (cin >> m >> n && m > 0){
        cout << f(n) - f(m-1) << endl;
    }
    
    
    return 0;
}