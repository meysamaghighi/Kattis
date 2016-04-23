// Meysam Aghighi
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a,a);
}

ll mod_inv(ll a, ll b){
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

ll mul(ll x, ll y, ll n){
    return (x*y)%n; // to be fixed! long long out of range!!
}

int main(){
    ll n;
    int t;
    while (cin >> n >> t && (n || t)){
        while (t--){
            ll x,y,m;
            char o;
            cin >> x >> o >> y;
            if (o == '+') m = (x - n) + y;
            else if (o == '-') m = x - y;
            else if (o == '/'){
                if (gcd(y,n) != 1){ // Modular Inverse doesn't exist
                    cout << "-1" << endl;
                    continue;
                }
                m = mul(x,mod_inv(y,n),n);
            }
            else m = mul(x,y,n);
            if (m < 0) m += n;
            cout << m << endl;
        }
    }
    return 0;
}