//Meysam Aghighi
#include <bits/stdc++.h>

using namespace std;

int main(){
    int r,h,s;
    while (cin >> r >> h >> s && r){
        double ans = 2*r*(M_PI-acos((double)r/h)) + 2*sqrt(h*h-r*r);
        ans += ans*s/100;
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}