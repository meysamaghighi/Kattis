#include<bits/stdc++.h>
using namespace std;

int main(){

	int a00,a01,a10,a11;
	cin >> a00 >> a01 >> a10 >> a11;
	int n = (sqrt(1+8*a00)+1)/2;
	int m = (sqrt(1+8*a11)+1)/2;
	bool can = true;
	if (a00 == 0) n = 0;
	if (a11 == 0) m = 0;
	if (n*n-n != 2*a00 || m*m-m != 2*a11) can = false;
	if (a01 + a10 != m*n) can = false;
	if (can){ // take care of n OR m equal to 0!
		int k = a10/n , q = a10%n;
		for (int i=0;i<k;i++) cout << "1";
		for (int i=0;i<n-q;i++) cout << "0";
		cout << "1";
		for (int i=0;i<q;i++) cout << "0";
		for (int i=0;i<m-k-1;i++) cout << "1";
		cout << endl;
	}
	else cout << "Impossible" << endl;
	
	
	return 0;
}
