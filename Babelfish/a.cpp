#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main(){
    map <string,string> m;
    string s,s1,s2;
    while (getline(cin,s) && s.size()){
        stringstream ss(s);
        ss >> s1;
        ss >> s2;
        m[s2] = s1;
    }
    while (getline(cin,s)){
        if (m.count(s)){
            cout << m[s] << endl;
        }
        else cout << "eh" << endl;               
    }
    
    return 0;
}