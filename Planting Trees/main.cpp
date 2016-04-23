#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int a[100000];
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    int answer = 0;
    for (int i=0;i<n;i++)
        if (a[i]+n-i > answer)
            answer = a[i]+n-i;
    cout << answer + 1 << endl;
    return 0;
}