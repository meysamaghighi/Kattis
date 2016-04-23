// Meysam Aghighi
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a,a);
}

void print(ll num, ll den){
    bool pos = (num>0 && den>0) || (num<0 && den<0);
    if (num<0) num = -num;
    if (den<0) den = -den;
    ll d = gcd(num,den);
    num /= d , den /= d;
    if (num==0 || den==0) cout << "0 / 1" << endl;
    else cout << (pos?"":"-") << num << " / " << den << endl;
}

void add_sub(ll x1, ll y1, ll x2, ll y2, int state){
    ll num = x1*y2 + state*x2*y1;
    ll den = y1*y2;
    print(num,den);
}

void mul(ll x1, ll y1, ll x2, ll y2){
    ll num = x1*x2;
    ll den = y1*y2;
    print(num,den);
}

int main(){
    int t; cin >> t;
    while (t--){
        ll x1,y1,x2,y2;
        char o;
        cin >> x1 >> y1 >> o >> x2 >> y2;
        if (o == '+') add_sub(x1,y1,x2,y2,1);
        else if (o == '-') add_sub(x1,y1,x2,y2,-1);
        else if (o == '/') mul(x1,y1,y2,x2);
        else mul(x1,y1,x2,y2);
    }
    return 0;
}