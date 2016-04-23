// Meysam Aghighi

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n,p;
    bool found,neg;
    double x;
    while (cin >> n && n){
        found = false;
        neg = false;
        if (n < 1){
            neg = true;
            n = -n;
        }
        for (p=31;!found && p>=1;p--){
            x = pow(n,1.0/p);
            if (x-floor(x) < 0.001){
                if (pow(floor(x),p) == n){
                    if (!neg || p%2){
                        cout << p << endl;
                        found = true;
                    }
                }
            }
            else if (ceil(x)-x < 0.001){
                if (pow(ceil(x),p) == n){
                    if (!neg || p%2){
                        cout << p << endl;
                        found = true;
                    }
                }
            }
        }
    }

    return 0;
}
