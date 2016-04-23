#include <iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    getline(cin,s);
    for (int i=0;i<n;i++){
        getline(cin,s);
//        cout << i << ": " << s << endl;
        if (s.compare(0,10,"Simon says") == 0)
            cout << s.substr(11,s.size()-11) << endl;
    }
    return 0;
}