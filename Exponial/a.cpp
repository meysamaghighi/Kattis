//Meysam Aghighi
// Euler's totient(phi) + a^n mod m
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pow_mod(ll n, ll k, ll m){ // returns n^k mod m
    ll ans = 1;
    while (k){
        if (k & 1) ans = (ans * n) % m;
        k /= 2;
        n = (n * n) % m;
    }
    return ans;    
}

ll phi(ll n){    
    ll tot = 1;
    for (ll i=2;i*i<=n;i++){
        if (n%i==0){
            tot *= i-1;
            n /= i;
            while (n%i==0){
                tot *= i;
                n /= i;
            }
        }
    }
    if (n>1) tot *= n-1;
    return tot;
}

ll solve(ll n, ll m){
    if (m == 1) return 0;
    if (n == 1) return 1;
    if (n == 2) return pow_mod(2, 1, m);
    if (n == 3) return pow_mod(3, 2, m);
    if (n == 4) return pow_mod(4, 9, m);
    ll tot_m = phi(m);
    return pow_mod(n, tot_m+solve(n-1,tot_m), m); 	// we need to add tot_m because if solve(n-1,tot_m) returns 0 and
													// gcd(n,m) > 1, without adding tot_m the answer will be wrong.
}

int main(){
    ll n,m; cin >> n >> m;
    cout << solve(n,m) << endl;
    return 0;
}
