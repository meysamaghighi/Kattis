// Meysam Aghighi
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main(){
    ull n;
    cin >> n;
    vector<pair<ull,ull> > a;
    for (int i=2;i<=sqrt(n);i++){
        int temp = 0;
        while (n%i == 0){
            temp++;
            n/=i;
        }
        if (temp != 0) a.push_back(make_pair(i,temp));
    }
    if (n != 1) a.push_back(make_pair(n,1));
    ull best1 = n, best2 = 0;
    for (int i=0;i<a.size();i++){
        if (best2 < a[i].second){
            best1 = a[i].first;
            best2 = a[i].second;
        }
    }
    cout << best1 << endl;
    return 0;
}