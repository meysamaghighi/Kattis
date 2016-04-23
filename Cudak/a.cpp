// Meysam Aghighi

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;


const int L = 17;
const int Sum = 136;
long long g[L][Sum];

void init(){
	for (int i=0;i<L;i++)
		for (int j=0;j<Sum;j++)
			g[i][j] = 0;
	g[0][0] = 1;
	for (int i=0;i<10;i++)
		g[1][i] = 1;
	for (int i=2;i<L;i++)
		for (int j=0;j<Sum;j++)
			for (int k=0;k<10 && j-k>=0;k++)
				g[i][j] += g[i-1][j-k];
}

long long f(long long n, int s){ // gives the total number of numbers in [1,n] with digit sum s
	if (s<0) return 0;
	if (n==0 && s==0) return 1;
	if (n==0) return 0;
	long long sum = 0, m = n;
	int last, l = 0;
	while(m){
		last = m%10;
		m /= 10;
		l++;
	}
	if (l==1){
		if (s<=n) return 1;
		else return 0;
	}
	for (int i=0;i<last && s-i>=0;i++)
		sum += g[l-1][s-i];
	return (sum + f(n-last*pow(10,l-1),s-last));
}

long long first(long long A, long long B, int s){ // finds the first with binary search
	long long hi = B,lo = A,mid;
	while(lo != hi){
		mid = (lo+hi+1)/2;
		if (f(mid,s)-f(lo,s))
			hi = mid-1;
		else
			lo = mid;
	}
	return lo+1;
}

int main(){
	long long A,B;
	int S;
	init();
	cin >> A >> B >> S;
//	cout << f(B,S) << endl;
//	cout << f(A-1,S) << endl;
	cout << f(B,S)-f(A-1,S) << endl;
	cout << first(A,B,S) << endl;
    return 0;
}
