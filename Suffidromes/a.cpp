// Meysam Aghighi
#include <iostream>
#include <cstring>
using namespace std;

bool is_palindrome(string s){
    if (s.size()==0) return true;
    int n = s.size();
    for (int i=0;i<n/2;i++) if (s[i] != s[n-1-i]) return false;
    return true;
}

int main(){
    string a,b;
    while (getline(cin,a) && getline(cin,b)){
        if (a == b){
            cout << "No solution." << endl;
            continue;
        }
        int t=0, n=a.size(), m=b.size(), i;
        string ans;
        while (a[t]==b[t]) t++;
        for (i=0;i<=n && i<=m;i++){
            bool aa = is_palindrome(a.substr(i,n-i)), bb = is_palindrome(b.substr(i,m-i));
            if (aa && !bb) ans = a;
            else if (!aa && bb) ans = b;
            else if (aa && bb && i>t){
                int j = i-1;
                while (a[j]==b[j] && j>=0) j--;
                ans = a[j]<b[j]?a:b;
            }
            else continue;
            for (int j=i-1;j>=0;j--) cout << ans[j];
            cout << endl;
            break;
        }
        if (i>n || i>m){
            ans = i>n?b:a;
            if (ans[i-1]=='a' && is_palindrome(ans.substr(i,ans.size()-i))) cout << "b";
            else cout << "a";
            ans = i>n?a:b;
            for (int j=ans.size()-1;j>=0;j--) cout << ans[j];
            cout << endl;
        }
    }
    return 0;
}