#include <iostream>
#include <string>
using namespace std;

int main(){
    string ss;
    int s = 0;
    cin >> ss;
    for(int i=0;i<ss.size();i+=3){
        if (ss.at(i)!='P')
            s++;
        if (ss.at(i+1)!='E')
            s++;
        if (ss.at(i+2)!='R')
            s++;

    }
    cout << s << endl;
    return 0;
}