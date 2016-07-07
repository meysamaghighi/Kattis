// Meysam Aghighi
#include <bits/stdc++.h>
using namespace std;

#define h(i) (i==0?"+":i==1?"-":i==2?"*":"/")

struct expp{
    int i,j,k;
    expp(){}
    expp(int i,int j, int k): i(i), j(j), k(k){}
};

int eq(int sign, int n, int *o){ // complete this part
    if (n == 1) return sign * 4;
    int s = sign * 4;
    for (int i=0;i<n-1;i++){
        if (o[i] == 0) return eq(sign,i+1,o) + eq( 1,n-i-1,o+i+1);
        if (o[i] == 1) return eq(sign,i+1,o) + eq(-1,n-i-1,o+i+1);
        if (o[i] == 2) s *= 4;
        if (o[i] == 3) s /= 4;
    }
    return s;
}

map <int,expp> memo;

void init(){
    int * o; o = new int[3];
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            for (int k=0;k<4;k++){
                o[0] = i; o[1] = j; o[2] = k;
                memo[eq(1,4,o)] = expp(i,j,k);
            }
        }
    }
}

int main(){
    init();
    int n,m;
    cin >> m;
    while (m--){
        cin >> n;
        if (memo.count(n)) {
           int i = memo[n].i, j = memo[n].j, k = memo[n].k;
           cout << "4 " << h(i) << " 4 " << h(j) << " 4 " << h(k) << " 4 = " << n << endl;
        }
        else cout << "no solution\n";
    }
    
    return 0;
}