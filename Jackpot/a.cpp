//Meysam Aghighi
#include <iostream>
using namespace std;

typedef long long T;

T gcd(T a, T b){
    if (a==0) return b;
    return gcd(b%a,a);
}

T lcm(T a, T b){
    T l = a/gcd(a,b)*b;
    cerr << l << endl;
    if (l < 0 || l>1000000000) return -1;
    return l;
}

int main(){
    int n,w,x,ans;
    cin >> n;
    while (n--){
        cin >> w;
        ans=1;
        while (w--){
            cin >> x;            
            if (ans != -1) ans = lcm(ans,x);            
        }
        if (ans != -1) cout << ans << endl;
        else cout << "More than a billion." << endl;        
    }
    return 0;
}