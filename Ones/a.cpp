//Meysam Aghighi

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >> n){
        int x = 1, ans = 1;
        while (x % n != 0){
           x = 10*x + 1;
           x %= n;
           ans++;
        }
        cout << ans << endl;
    }
    return 0;
}