// Meysam Aghighi

#include <iostream>
#include <cmath>
using namespace std;

inline int min (int a,int b){
    return (a<b?a:b);
}

int main(){
    int t,n,n1,n5,n10;
    cin >> t;
    while (t){
        t--;
        cin >> n;
        cin >> n1;
        cin >> n5;
        cin >> n10;

        int answer = 0;

        int temp = min(n,n10);
        answer += temp;
        n -= temp;

        if(n>0){
            if (n>=n5){ // fill every 8 with a 5 until you can't
                answer += n5 + 8*n - 5*n5;
            }
            else{ // double fill until you can
                answer += n;
                n5 -= n;
                temp = min(n,n5);
                answer += temp;
                n -= temp;
                if(n>0){
                    answer += n*3;
                }
            }
        }


        cout << answer << endl;
    }
    return 0;
}
