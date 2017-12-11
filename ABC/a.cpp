//Meysam Aghighi
// EZ!
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3];
    for (int i=0;i<3;i++) cin >> a[i];
    sort(a,a+3);
    string s; cin >> s;
    assert(s.size() == 3);
    for (int i=0;i<3;i++) cout << a[s[i]-'A'] << " ";    
    return 0;
}
