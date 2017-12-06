// Meysam Aghighi
// Fermat's little theorem, preprocessing, binary search
#include <bits/stdc++.h>
using namespace std;

long long p = 1e9+7;
long long powers_nine[10] = {
1,
9,
81,
729,
6561,
59049,
531441,
4782969,
43046721,
387420489
};

long long f(long long d){ // returns (9^d)%p
	if (d < 10) return powers_nine[(int)d];
	long long temp = f(d/2);
	if (d % 2 == 0)	return (temp * temp) % p;
	return (9 * temp * temp) % p;
}

int main(){
	
	// long long x = 1;
	// while (x < p){
	// 	cout << x << "," << endl;
	// 	x *= 9;
	// }

	int t;
	long long d,ans;
	cin >> t;
	while (t--){
		cin >> d;
		ans = 8;
		d %= p-1; // Fermat's little theorem
		ans = (ans * f(d-1)) % p;
		cout << ans << endl;
	}
    return 0;
}
