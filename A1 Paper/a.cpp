// Meysam Aghighi
// Easy: a small trick to calculate the glued perimeter
#include <bits/stdc++.h>
using namespace std;

int main(){
    int req = 1;
    double perimeter = 0.0, p2 = 2.0*(pow(2.0,-5.0/4)+pow(2.0,-3.0/4));
    double p1 = sqrt(2)*p2;
    
    int n,x; cin >> n;
    
    for (int i=2;i<=n && req>0;i++){
        req *= 2;              
        cin >> x;
        if (x >= req) { // we're done
            perimeter += req*p2;
            req = 0; 
        }
        else {
            req -= x;
            perimeter += x*p2;
        }
        p2 /= sqrt(2);
    }
    
    double answer = (perimeter - p1)/2.0; // here's the trick! ;)
    if (req == 0.0) printf("%.10f\n",answer); // double check if condition (diff < eps) -> No need, got accepted!
    else cout << "impossible" << endl;
    
    return 0;
}