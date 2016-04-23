#include <iostream>
using namespace std;

int main(){
    int n,s,t1,t0,answer;
    while(cin >> n){
        answer = 0;
        t0 = 0;
        if (n == -1)
            break;
        for (int i=0;i<n;i++){
            cin >> s;
            cin >> t1;
            answer += s * (t1-t0);
            t0 = t1;
        }
        cout << answer << " miles" << endl;
    }
    return 0;
}