// Meysam Aghighi
#include <iostream>
#include <cstring>
using namespace std;

bool solve(string s){
    if (s.size() < 4) return true;
    int d,cur=0,next;
    for (int i=1;i<s.size();i++){
        if (s[i]=='*'){
            d = i;
            break;
        }
    }
    for (next=1;next<s.size();next++){
        if (s[next]=='*'){
            if(next-cur != d) return false;
            cur = next;
        }
    }
    return true;
}

int main(){
    string s;
    int t = 1;
    while (cin >> s && s[0]!='E'){
        cout << t++ << " ";
        if (solve(s)) cout << "EVEN\n";
        else cout << "NOT EVEN\n";
    }
    return 0;
}