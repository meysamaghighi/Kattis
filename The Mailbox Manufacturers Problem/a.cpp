// Mega Noobs
#include <iostream>
#include <cstring>
using namespace std;

#define INF 1000000000

int sol[110][110][11];

int sum(int n){
	return n*(n+1)/2;
}

int solve(int A, int B, int k){
//	cerr << A << " " << B << " " << k << endl;
	if (k == 1) return sum(B)-sum(A);
	if (A >= B) return 0; // check
//	if (A+1 == B) return A+B; // check
	int temp = INF;
	if (sol[A][B][k] == -1){
		for (int mid = A+1; mid <= B; mid++){
			temp = min( temp , max( solve(A,mid-1,k-1) , solve(mid,B,k) ) + mid );
		}
		sol[A][B][k] = temp;
	}
	return sol[A][B][k];
}

int main(){
	int N,k,m;
	cin >> N;
	while (N--){
		memset(sol,-1,sizeof(sol));
		cin >> k >> m;
		cout << solve(0,m,k) << endl;
	}
	return 0;
}
