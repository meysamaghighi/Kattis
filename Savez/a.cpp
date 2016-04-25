// Meysam Aghighi
// This is TLE!
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

bool check(string s1, string s2) {
    if (s2.substr(0,s1.size())==s1 && s2.substr(s2.size()-s1.size(),s1.size())==s1) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    string s[n];
    for (int i=0;i<n;i++) cin >> s[i];
    
    vector<int> a(n,1);
    int best=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (check(s[j],s[i])) a[i] = a[j]+1;
        }
    }
    for (int i=0;i<n;i++) best = max(best,a[i]);
    cout << best << endl;

    return 0;
}