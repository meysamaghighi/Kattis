// Meysam Aghighi
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;

bool is_palindrome(string s){
    if (s.size()==0) return true;
    int n = s.size();
    for (int i=0;i<n;i++) if (s[i] != s[n-1-i]) return false;
    return true;
}

int main(){
    string a,b;
    char A[2000],B[2000];
    while (gets(A) && gets(B)){
        a = A;
        b = B;
        if (a == b){
            cout << "No solution." << endl;
            continue;
        }
        // cerr << a << " " << b << endl;
        int t=0, n=a.size(), m=b.size(), i;
        string ans;
        while (a[t]==b[t]) t++;
        for (i=0;i<=n && i<=m;i++){
            bool aa = is_palindrome(a.substr(i,n-i)), bb = is_palindrome(b.substr(i,m-i));
            // cerr << aa << " " << bb << endl;
            if (aa && !bb) ans = a;
            else if (!aa && bb) ans = b;
            else if (aa && bb && i>t){
                int j = i-1;
                while (a[j]==b[j] && j>=0) j--;
                ans = a[j]<b[j]?a:b;
            }
            else continue;
            {
                for (int it=i-1;it>=0;it--) cout << ans[it];
                cout << endl;
                // cerr << "yo" << endl;
                break;
            }
        }
        // cerr << i << " " << n << " " << m << endl;
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