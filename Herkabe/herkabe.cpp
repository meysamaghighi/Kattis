// Meysam Aghighi
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
#define N 1000000007
ull fact[3001];
string s[3001];

void init(){
    fact[0] = 1;
    for (ull i=1;i<3001;i++) fact[i] = i*fact[i-1]%N;
}

int solve(int l, int r, int x){ // s[l] to s[r] have first x chars the same
    if (l>=r-1) return 1;
    ull ans=1,k=1,cur=l;
    // cerr << l << " " << r << " " << x << endl;
    for(int i=l+1;i<r;i++){
        if (s[cur][x] != s[i][x]){
            ans = ans*solve(cur,i,x+1)%N;
            k++;
            cur = i;            
        }
    }
    ans = ans*solve(cur,r,x+1)%N;
    ans = ans*fact[k]%N;
    return ans;    
}

int main(){
    init();
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> s[i];
    sort(s,s+n);
    cout << solve(0,n,0) << endl;
    return 0;
}