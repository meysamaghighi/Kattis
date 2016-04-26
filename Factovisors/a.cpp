// Meysam Aghighi
// Question: m|n!?
#include <cstdio>
#include <cmath>
using namespace std;

bool solve(int n, int m){
    if (m == 0) return false;
    if (m == 1 && n == 0) return true;
    for (int i=2,rm=sqrt(m)+1,k,p;i<rm && m>n;i++){
        k=0, p=i;
        while (m%i==0) m/=i, k++; // max k where i^k|m
        while (p<=n && k>0) k-=n/p, p*=i; // max kk where i^kk|n! (the other way)
        if (k>0) return false;
    }
    return m <= n;    
}

int main(){
    int m,n;
    while (scanf("%d %d",&n,&m)==2){
        if (solve(n,m)) printf("%d divides %d!\n",m,n);
        else printf("%d does not divide %d!\n",m,n);
    }
    
    return 0;
}
