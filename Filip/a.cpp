//Meysam Aghighi
// EZ!
#include<bits/stdc++.h>
using namespace std;

int main(){
	int a=0,b=0,t=1; string s;
	cin >> s; for(int i=0;i<3;i++) a+=(s[i]-'0')*t,t*=10;
	t=1;
	cin >> s; for(int i=0;i<3;i++) b+=(s[i]-'0')*t,t*=10;
	cout << max(a,b) << endl;
	return 0;
}
