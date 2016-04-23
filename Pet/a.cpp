#include <iostream>
using namespace std;

int main(){
    int a,b,c,d;
    int x=1,i=1,s=0;
    while(cin>>a){
        cin >> b;
        cin >> c;
        cin >> d;
        if (a+b+c+d>s){
            x = i;
            s = a+b+c+d;
        }
        i++;
    }
    cout << x << " " << s << endl;
    return 0;
}
