#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    n = n%2;
    string s1,s2;
    cin >> s1;
    cin >> s2;
    for (int i=0;i<s1.size();i++){
        if ( ((s1.at(i)==s2.at(i))&&n) || (!(s1.at(i)==s2.at(i))&&!n) ){
            cout << "Deletion failed" << endl;
            return 0;
        }
    }
    cout << "Deletion succeeded" << endl;
    return 0;
}