// Meysam Aghighi
// Note: the problem definition says "proper superset"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> multi_set(string s){
    vector<int> a(26,0);
    for (int i=0;i<s.size();i++) a[s[i]-'a']++;
    return a;
}

int main(){
    string s;
    map <string, vector<int> > myMap;
    while (cin >> s && s[0] != '0'){
        myMap[s] = multi_set(s);
    }
    
    bool dominated, print;
    for (map<string, vector<int> >::iterator i=myMap.begin(); i!=myMap.end(); i++){
        print = true;
        for (map<string, vector<int> >::iterator j=myMap.begin(); j!=myMap.end() && print; j++){
            if (i == j) continue;
            dominated = true;
            int s1 = 0, s2 = 0;
            for (int k=0;k<26 && dominated;k++){
                if (i->second[k] > j->second[k])
                    dominated = false;
                s1 += i->second[k]; s2 += j->second[k];
            }
            if (s1 == s2) dominated = false; // checks the equality case: sam , mas
            if (dominated) print = false; // j dominates i
        }
        if (print) cout << i->first << endl; // nothing dominated i
    }
    
    return 0;
}