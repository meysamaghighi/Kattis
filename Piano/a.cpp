// Meysam Aghighi

#include <iostream>
using namespace std;

int main(){
    int t,m,p;
    int a,b;
    int weekend;
    int state;
    cin >> t;
    while (t){
        t--;
        cin >> m;
        cin >> p;
        int day[101] = {0};
        weekend = 0;
        state = 1;
        for (int i=0;i<m;i++){
            cin >> a;
            cin >> b;
            if (a%7==0 || a%7==6)
                weekend++;
            if (b%7==0 || b%7==6)
                weekend++;
            cout << a << "," << b << endl;
            int j = a;
            while (j<=b)
                ++day[j++];
        }
        for (int i=0;i<101;i++)
            if (day[i]>p){
                cout << "serious trouble" << endl;
                state = 0;
                break;
            }
        if (state){
            if (weekend>1)
                cout << "weekend work" << endl;
            else
                cout << "fine" << endl;
        }

    }
    return 0;
}
