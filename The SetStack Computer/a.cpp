// Meysam Aghighi

#include <iostream>
#include <cstdio>
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
    int T,N;
    SET a,b;
    char s[20];
    cin >> T;
    while (T--){
        stack <int> st;
	keys.clear();
	sets.clear();
	cin >> N;
        while (N--){
           scanf("%s",s);
           if (s[0] == 'P')
            st.push(getKey(SET()));
           else if (s[0] == 'D'){
            st.push(st.top());
            }
           else {
            a = sets[st.top()];
            st.pop();
            b = sets[st.top()];
            st.pop();
	    SET c;
            if (s[0] == 'U')
                set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
            else if (s[0] == 'I')
                set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
            else if (s[0] == 'A'){
                c = b;
                c.insert(getKey(a));
            }
            st.push(getKey(c));
           }
           // cout << sets[st.top()].size() << endl;
	   printf("%lu\n",sets[st.top()].size());
        }
        //cout << "***" << endl;
	printf("***\n");
    }
    return 0;
}
