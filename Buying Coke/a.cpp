// Meysam Aghighi
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 2000

int t,C,N1,N5,N10;
int a[151][150][70];

int solve (int c, int n5, int n10){
    if (a[c][n5][n10] > 0) return a[c][n5][n10];
    if (c == 0) return 0;    
    int ans = INF;
    int n1 = N1 - (8*(C-c) - 5*(N5-n5) - 10*(N10-n10)); 
    if (n10) ans = min(ans, 1 + solve(c-1,n5,n10-1));
    if (n5>1) ans = min(ans, 2 + solve(c-1,n5-2,n10));
    if (n5 && n1>2) ans = min(ans, 4 + solve(c-1,n5-1,n10));
    if (n1>7) ans = min(ans, 8 + solve(c-1,n5,n10));
    if (n10 && n1>2) ans = min(ans, 4 + solve(c-1,n5+1,n10-1)); // This case is fucking stupid! I got wrong answers here...
    return a[c][n5][n10] = ans;
}

int main(){
    memset(a,-1,sizeof(a));
    scanf("%d",&t);
    while (t--){
        scanf("%d %d %d %d",&C,&N1,&N5,&N10);
        printf("%d\n",solve(C,N5,N10));
    }
    return 0;
}