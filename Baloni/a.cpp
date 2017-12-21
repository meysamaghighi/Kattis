//Meysam Aghighi
// EZ! I probably don't have the best solution...
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x; cin >> n;
	multiset<int> s;
	for (int i=0;i<n;i++) {
		cin >> x;
		if (s.count(x)) s.erase(s.find(x));		
		s.insert(x-1);
	}
	// for (auto i:s) cerr << i << " "; cerr << endl;
	cout << s.size() << endl;
	return 0;
}
