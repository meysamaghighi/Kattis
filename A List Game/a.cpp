//Meysam Aghighi

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, n, ans = 0, p = 2;
    cin >> N; n = N;
    while (n>1){
        if (p*p>N){
            ans++;
            break;
        }
        while (n%p==0){
            n /= p;
            ans++;            
        }
        p++;        
    }
    cout << ans << endl;
    return 0;
}