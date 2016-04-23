#include <iostream>
using namespace std;

int main(){
    int a[6] = {0};
    int n,x;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        x--;
        if (a[x]==0)
            a[x] = i+1;
        else
            a[x] = -1;
    }
    for (int i=5;i>=0;i--){
        if(a[i]>0){
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << "none" << endl;
    return 0;
}