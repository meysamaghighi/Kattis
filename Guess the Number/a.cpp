// Meysam Aghighi
// Binary search
#include <bits/stdc++.h>
using namespace std;


int main(){
	int lo = 1, hi = 1000, n;
	string s = "hi";
	while (true){
		n = (lo + hi)/2;
		cout << n << endl;
		cin >> s;
		if (s[0] == 'l') hi = n-1;
		else if (s[0] == 'h') lo = n+1;
		else break;
	}
    return 0;
}
