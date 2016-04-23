// Meysam Aghighi
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

map <string,int> cache;

bool can_be_pali(string s){
    vector<bool> a(26,0);
    int n = s.size();
    for (int i=0;i<n;i++) a[s[i]-'a'] = 1 - a[s[i]-'a'];
    int odds = 0;
    for (int i=0;i<26;i++) if (a[i]) odds++;
    if (odds>1 || (n%2==0 && odds>0) ) return false;
    return true;
}

int steps(string s){
    int n = s.size(), moves, t1, t2;
    int i = 0;
    while ((s[i] == s[n-1-i]) && i<n/2) i++;
    if (i) s = s.substr(i,n-2*i);
    n = s.size();
    if (n <= 1) return 0;
    if(cache.count(s)) return cache[s];
    // Case 1
    i = n-1;
    while (s[0] != s[i] && i) i--;
    if (i == 0) t1 = steps(s.substr(1,n-1)) + n/2;
    else t1 = steps(s.substr(1,i-1) + s.substr(i+1,n-i-1)) + n-i-1;
    // Case 2
    i = 0;
    while (s[i] != s[n-1] && i<n) i++;
    if (i == n) t2 = steps(s.substr(0,n-1)) + n/2;
    else t2 = steps(s.substr(0,i) + s.substr(i+1,n-i-2)) + i;
    
    return cache[s] = min(t1,t2);
}

int main(){
    int n;
    string s;
    cin >> n;
    getline(cin,s);
    while (n--){
        cache.clear();        
        // cin >> s;
        // scanf("%s",&s);
        getline(cin,s);
        if(can_be_pali(s)) cout << steps(s) << endl;        
        else cout << "Impossible" << endl;
    }
    return 0;
}