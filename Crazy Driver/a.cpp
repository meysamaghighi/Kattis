//Meysam Aghighi
// The idea is that the crazy driver tries to wastes in the best place (closest pair of gates)
// when he knows that he will need to waste time anyway.
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, now = 0;
	long long dist = 0;
	cin >> n;
	int c[n],t[n],m[n]; // m[i] = best place (distance) to waste time before gate i
	for (int i=1;i<n;i++) cin >> c[i]; m[1] = c[1];	
	for (int i=2;i<n;i++) m[i] = min(m[i-1],c[i]);
	for (int i=0;i<n;i++) cin >> t[i];
	for (int i=1;i<n;i++){
		dist += c[i];
		now++;
		if (now < t[i]){
			long long d = t[i] - now; // got a WA because d was int!
			if (d & 1) d++;
			now += d;
			dist += d*m[i];
		}
	}
	cout << dist << endl;
	return 0;
}
