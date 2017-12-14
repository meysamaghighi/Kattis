//Meysam Aghighi
// EZ!
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	set<string> maps;
	bool rep = false;
	while (cin >> s && !rep){
		if (!maps.count(s)) maps.insert(s);
		else rep = true;
	}
	if (rep) cout << "no" << endl;
	else cout << "yes" << endl;
	return 0;
}
