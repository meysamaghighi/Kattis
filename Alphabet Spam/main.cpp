#include <iostream>
using namespace std;

int main(){
    string s;
    int c1,c2,c3,c4;
    c1 = c2 = c3 = c4 = 0;
    cin >> s;
    for (int i=0;i<s.size();i++){
        if (s.at(i) == '_')
            c1++;
        else if (islower(s.at(i)))
            c2++;
        else if (isupper(s.at(i)))
            c3++;
        else
            c4++;
    }
    cout.precision(15);
    cout << (double)c1/s.size() << endl;
    cout << (double)c2/s.size() << endl;
    cout << (double)c3/s.size() << endl;
    cout << (double)c4/s.size() << endl;
    
    return 0;
}