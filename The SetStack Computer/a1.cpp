// Meysam Aghighi

#include <iostream>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef set <int> SET;
map <SET,int> keys;   
vector <SET> sets;   

int getKey(SET x){
	if (keys.count(x))
		return keys[x];
	sets.push_back(x);  
	return keys[x] = sets.size()-1;
}

int main(){
	SET x1,x2,x;
	int T,N;
	cin >> T;
	while (T--) {
		keys.clear();
		sets.clear();
		stack<int>st;
		cin >> N;
		while (N--) {
			string op;
			cin >> op;
			if (op[0] == 'P')
				st.push(getKey(SET()));
			else if (op[0] == 'D')
				st.push(st.top());
			else {
				x1 = sets[st.top()];
				st.pop();
				x2 = sets[st.top()];
				st.pop();
				if (op[0] == 'U')
					set_union(x1.begin(),x1.end(), x2.begin(),x2.end(), inserter(x,x.begin()));
				if (op[0] == 'I')
					set_intersection(x1.begin(),x1.end(), x2.begin(),x2.end(), inserter(x,x.begin()));
				if (op[0] == 'A') {
					x = x2;
					x.insert(getKey(x1));
					}
				st.push(getKey(x));
			}
			cout << sets[st.top()].size() << endl;
		}
		cout << "***" << endl;
	}
}
