// Meysam Aghighi
#include <iostream>
using namespace std;

typedef long long ll;

ll mod_inv(ll a, ll b){ // we must have gcd(a,b)=1, otherwise error!
    ll bb = b, temp, q;
    ll x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        temp = b, b = a % b, a = temp;
        temp = x0, x0 = x1 - q * x0, x1 = temp;
    }
    if (x1 < 0) x1 += bb;
    return x1;
}

int main(){
	ll T,a,m,b,n;
	cin >> T;
	while (T--){
		cin >> a >> n >> b >> m;
		ll K = n*m;
		ll x = (((a*m)%K)*mod_inv(m,n))%K;
		x += (((b*n)%K)*mod_inv(n,m))%K;		
		x %= K;
		cout << x << " " << K << endl;
	}
	return  0;
}