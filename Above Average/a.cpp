//Meysam Aghighi

#include <bits/stdc++.h>

using namespace std;

int main(){
    int c,n;
    cin >> c;
    while (c--){
        cin >> n;
        int s = 0, a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
            s += a[i];
        }
        double avg = (s + 0.0)/n;
        int m = 0; // how many are above average
        for (int i=0;i<n;i++) if (a[i] > avg) m++;
        double sol = (m+0.0)/n*100;
        cout << fixed << setprecision(3) << sol << "%" << endl;
    }
    return 0;
}
