// Meysam Aghighi

#include <iostream>
#include <algorithm>
//#include <vector>
#include <cstdio>
using namespace std;

//struct point {
//    int count;
//    long long x;
//};

//bool wayToSort(point a, point b) {
//    return a.x > b.x;
//}

int main(){
    long long m,S = 0;
    int n;
    cin >> m;
    cin >> n;
    long long a[n];
    for (int i=0;i<n;i++){
        scanf ("%lld",&a[i]);
        S += a[i];
    }

    // There is enough candy for all
    if (m >= S){
        cout << 0 << endl;
        return 0;
    }

    // There is at least some anger
    sort(a,a+n);

    // Binary search to find the optimal value d
    long long low=0,high=a[n-1]-1,d;
    while (low!=high){
        d = (low+high+1)/2;
        long long sum = 0;
        for (int i=0;i<n;i++){
            sum += (a[i]>d?a[i]-d:0);
        }
        if (sum<m)
            high = d-1;
        else
            low = d;
    }

    // d+1 values
    d = low + 1;

    for (int i=0;i<n;i++){
        if (a[i]>d){
            m -= a[i]-d;
            a[i] = d;
        }
    }

    // d values
    d--;

    for (int i=0;i<n && m>0;i++){
        if (a[i]>d){
            a[i]--;
            m--;
        }
    }


    long long sum = 0;
    for (int i=0;i<n;i++){
        sum += a[i]*a[i];
    }
    cout << sum << endl;

    return 0;
}
