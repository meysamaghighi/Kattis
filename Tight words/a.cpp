// Meysam Aghighi
// DP
#include <bits/stdc++.h>
using namespace std;

// 1 <= l <= n, 0 <= i <= k
// f[l][i] = percentage of tight words of length l that end in i over {0,1,...,k}
// answer = f[n][0] + f[n][1] + ... + f[n][k]

// f[l][0] = (f[l-1][0] + f[l-1][1])*[(k+1)^(l-1)]/[(k+1)^l] = (f[l-1][0] + f[l-1][1])/(k+1)    // simplified
// f[l][i] = (f[l-1][i-1] + f[l-1][i] + f[l-1][i+1])/(k+1);
// f[l][k] = (f[l-1][k-1] + f[l-1][k])/(k+1);

double f[101][10];
int n,k;

int main(){
	int k,n;
	while (cin >> k >> n){
		for (int i=0;i<=n;i++) for (int j=0;j<=k;j++) f[i][j] = 0;
		for (int j=0;j<=k;j++) f[1][j] = 100.0/(k+1);
		for (int l=2;l<=n;l++){
			f[l][0] = (f[l-1][0] + f[l-1][1])/(k+1);
			for (int i=1;i<k;i++) f[l][i] = (f[l-1][i-1] + f[l-1][i] + f[l-1][i+1])/(k+1);
			f[l][k] = (f[l-1][k-1] + f[l-1][k])/(k+1);
		}
		double ans = 0.0;
		for (int i=0;i<=k;i++) ans += f[n][i];
		cout << fixed << setprecision(8) << ans << endl;
	}
    return 0;
}
