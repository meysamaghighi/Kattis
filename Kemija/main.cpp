#include <iostream>
using namespace std;

int main(){
    char c,cc;
    while (cin >> noskipws >> c){
        if (c=='\n')
            break;
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            cin >> cc;
            cin >> cc;            
        }
        cout << c;
    }
    cout << endl;
    return 0;
}