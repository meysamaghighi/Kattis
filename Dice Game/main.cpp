#include <iostream>
using namespace std;

int main(){
    int a,b,c,d;
    double gunnar=0,emma=0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    gunnar = (a+b)/2. + (c+d)/2.;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    emma = (a+b)/2. + (c+d)/2.;

//    cout << gunnar << " " << emma << endl;
    
    if (gunnar>emma)
        cout << "Gunnar" << endl;
    else if (emma>gunnar)
        cout << "Emma" << endl;
    else
        cout << "Tie" << endl;
    return 0;
}