// Meysam Aghighi
// Implementation of Rabin-Karp string multi-matching algorithm
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

typedef vector <vector<int> > vvi;
#define d 256 // number of characters in the alphabet

// Rabin-Karp using hash values
vvi RK(const vector<string> & pat, const string txt, int q){
    int n = txt.size(), M = pat.size();
    vector<int> m;
    for (int i=0;i<M;i++) m[i] = pat[i].size(); // if error change to push_back()
    // int t = 0; // hash values pat & txt
    vector<int> p(M,0);
    vector<int> t(M,0);
    // int h = 1;
    vector<int> h(M,1);
    for (int j=0;j<M;j++)
    for (int i=0;i<m[j]-1;i++) h[j] = (h[j] * d) % q;    
    vvi ans;
 
    for (int j=0;j<M;j++)
    for (int i=0;i<m[j];i++){
        p[j] = (d*p[j] + pat[i])%q;
        t[j] = (d*t[j] + txt[i])%q;
    }
 
    for (int i=0;i<=n-m;i++){
        if (p == t && txt.substr(i,m) == pat) ans.push_back(i);
        if (i < n-m){
            t = (d*(t - txt[i]*h) + txt[i+m]) % q;
            if (t < 0) t += q;
        }
    }
    return ans;
}

int main(){
    string txt;
    int x;
    int n;
    while (cin >> n){
        vector<string> pat;
        getline(cin,txt);
        for (int i=0;i<n;i++){
            getline(cin,txt);
            pat.push_back(txt);
        }
        getline(cin,txt);
        vvi t = vvi(RK(pat,txt,101));
        for (int j=0;j<t.size();j++){
            for (int k=0;k<t[j].size();k++) cout << t[j][k] << " ";
            cout << endl;
        }        
    }
    
    return 0;
}