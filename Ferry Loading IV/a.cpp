#include <iostream>
using namespace std;

int main(){
    int t,n,x,l;
    cin >> t;
    while (t--){
        int fill = 0;
        int ll = 0 , rr = 0;
        string s;
        cin >> l >> n;
        l *= 100;
        int L[n] , R[n];
        for (int i=0;i<n;i++){
            cin >> x;
            cin >> s;
            if (s == "left") L[ll++] = x;
            else R[rr++] = x;            
        }
        int answerl = 0 , answerr = 0 , answer;
        for (int i=0;i<ll;i++){
            if (fill + L[i] <= l) fill += L[i];
            else answerl++ , fill = L[i];
        }
        if (ll) answerl++;
        fill = 0;
        for (int i=0;i<rr;i++){
            if (fill + R[i] <= l) fill += R[i];
            else answerr++ , fill = R[i];
        }
        if (rr) answerr++;
        if (answerl > answerr) answer = 2*answerl-1;
        else answer = 2*answerr;
         
        cout << answer << endl;
    }
    return 0;
}

// cerr << p << endl;
// cerr << answer << " " << place << " " << fill << endl;
// if (p != place){ // need to move to the other side ==> wrong! probably!
//     place = p;
//     answer++;
//     fill = x;
// }
// else if (x + fill <= l*100){ // don't need to move and has free space
//     fill += x;
// }
// else { // is full
//     answer += 2;
//     fill = x;
// }