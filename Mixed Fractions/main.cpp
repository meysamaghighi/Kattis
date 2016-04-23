#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b;
    while (cin>>a){
        cin >> b;
        if (a!=0)
            cout << (int)a/b << " " << a%b << " / " << b << endl;
        else
            break;
    }
    return 0;
}

