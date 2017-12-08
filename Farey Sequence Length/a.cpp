// Meysam Aghighi
// Euler's totient product formula + preprocessing
#include <bits/stdc++.h>
using namespace std;

#define N 10000
int ans[N],p[N];
long long s[N];

void totient(){
	for (int i=2;i<=N;i++) s[i] = i;
	for (int i=2;i<N;i++){
		if (p[i] == 0){ // i is prime
			int t = 2*i;
			while (t <= N){
				p[t] = 1;
				s[t] = s[t]*(i-1)/i;
				t += i;
			}
			s[i] = i-1;
		}
	}
}

void solve(){
	ans[2] = 3;
	for (int i=3;i<=N;i++){		
		ans[i] = ans[i-1] + s[i];
	}
}

int main(){
	totient();
	solve();
	int p,n,x;
	cin >> p;
	for (int i=1;i<=p;i++){
		cin >> x >> n;
		cout << i << " " << ans[n] << endl;
	}
    return 0;
}
