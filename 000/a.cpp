#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(const int * a, int n, long long sum){
    if (sum % 2 == 1) return 0;
    sum /= 2;
    long long temp_sum = sum;
    int pivot = 0;
    for (int i=0;i<n;i++){
        temp_sum -= a[i];
        if (temp_sum == 0){
            pivot = i+1;
            break;
        }
    }
    if (pivot == 0) return 0;
    return 1 + max(solve(a,pivot,sum) , solve(a+pivot,n-pivot,sum));
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    cin >> t;
    while (t--){
        cin >> n;
        int a[n];
        long long sum = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        cout << solve(a,n,sum) << endl;
    }
    return 0;
}
