//Meysam Aghighi
// backtrack
#include<bits/stdc++.h>
using namespace std;

set<char> letters;
map<char,int> mp;
bool mark[10];
int n;
string s[10];
set<char>::iterator h;

int isValid(){ // checks if an assignment is valid or not
	for (int i=0;i<n;i++) if (mp[s[i][0]]==0) return 0; // left-most digit of some word is 0
	long long _s[n], _sum = 0;
	for (int i=0;i<n;i++){ // words to numbers
		_s[i] = 0;
		int pow = 1;
		for (int j=s[i].size()-1;j>=0;j--){
			_s[i] += mp[s[i][j]]*pow;
			pow *= 10;
		}
		_sum += _s[i];
	}
	if (_sum == 2*_s[n-1]) return 1;
	return 0;
}

int bt(){
	if (h == letters.end()) return isValid();
	int ans = 0;
	for (int i=0;i<10;i++){
		if (!mark[i]){
			mp[*h] = i;
			mark[i] = true;
			h++;
			ans += bt();
			h--;
			mark[i] = false;
		}
	}
	return ans;
}

int main(){
	memset(mark,false,sizeof(mark));
	cin >> n;	
	for (int i=0;i<n;i++){
		cin >> s[i];
		for (int j=0;j<s[i].size();j++) letters.insert(s[i][j]);
	}
	h = letters.begin();
	cout << bt() << endl;
    return 0;
}
