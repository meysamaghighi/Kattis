// Meysam Aghighi
// Dynamic programming
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int t,n;
    cin >> t;
    while (t--){
        cin >> n;
        int p[n], s[n];
        for (int i=0;i<n;i++) cin >> s[i] >> p[i];
        double sol[151]; memset(sol,0,sizeof(sol));
        sol[0] = 1.0;
        for (int i=0;i<n;i++){
            for (int ss=150;ss>=s[i];ss--){
                sol[ss] = max(sol[ss] , p[i]/100.0*sol[ss-s[i]]);
            }
        }
        double best = 0.0;
        for (int ss=76;ss<151;ss++) best = max(best , sol[ss]);
        best *= 100.0;
        printf("%.6lf\n",best);
    }
    return 0;
}