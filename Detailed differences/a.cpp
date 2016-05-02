// Meysam Aghighi
#include <iostream>
using namespace std;

int main(){
    int n;
    string a,b;
    cin >> n;
    while (n--){
        cin >> a >> b;
        cout << a << "\n" << b << "\n";
        for (int i=0;i<a.size();i++){
            if (a[i] == b[i]) cout << ".";
            else cout << "*";
        }
        cout << "\n\n";
    }
    return 0;
}