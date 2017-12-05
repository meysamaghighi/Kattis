// Meysam Aghighi
#include <bits/stdc++.h>
using namespace std;

long long n,x,y;
int k,q;

int main(){
	cin >> n >> k >> q;
	while (q--){
		scanf("%lld%lld",&x,&y);
		int ans = 0;
		if (k == 1){ // tricky case
			ans = abs(x-y);
			x = y;
		}
		while (x != y){
			if (x>y) swap(x,y); // assume: x < y
			int t = y%k;
			// dad(y) will replace y
			if (t == 0 || t == 1) y = y/k;
			else y = y/k+1;
			ans++;			
		}
		printf("%d\n",ans);
	}
	
	return 0;
}