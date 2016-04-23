#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a;
    cin >> b;
    cout << (b>=45?a:(a+23)%24) << " " << (b+15)%60 << endl;
           
    return 0;
}