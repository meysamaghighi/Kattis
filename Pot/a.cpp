// Meysam Aghighi
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,x,s=0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        s += pow((x/10),(x%10));
    }
    cout << s << endl;
    return 0;
}
