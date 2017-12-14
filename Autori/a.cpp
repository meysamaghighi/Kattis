//Meysam Aghighi
// EZ!
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin >> s;
	bool flag = true;
	for (int i=0;i<s.length();i++) if (flag) t.push_back(s[i]), flag = false; else if (s[i]=='-') flag = true;
	cout << t << endl;
	return 0;
}
