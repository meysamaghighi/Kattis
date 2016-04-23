#include <iostream>
#include <algorithm>
using namespace std;

struct obj {
    int x , id;
    obj(){}
    bool operator < (obj o) const {
        return x < o.x;
    }
};

int main(){
    int n,t;
    while (cin >> n){
        obj a[n];
        int b[n],sol[n];
        for (int i=0;i<n;i++){
            cin >> a[i].x;
            a[i].id = i;
        }
        sort(a,a+n);
        for (int i=0;i<n;i++){
            cin >> b[i];     
        }
        sort(b,b+n);
        for (int i=0;i<n;i++){
            t = a[i].id;
            sol[t] = b[i]; 
        }
        for (int i=0;i<n;i++){
            cout << sol[i] << endl;
        }
        cout << endl;
    }
    return 0;
}