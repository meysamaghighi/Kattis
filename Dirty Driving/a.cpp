//Meysam Aghighi
// EZ!
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,p; cin >> n >> p;
	int a[n];
	for (int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	int x = 0;
	for (int i=0;i<n;i++) x = max(x, p*(i+1)-a[i]+a[0]);
	cout << x << endl;
    return 0;
}
