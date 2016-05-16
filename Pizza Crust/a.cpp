// Meysam Aghighi
#include <cstdio>
using namespace std;

int main(){
    int r,c;
    double ans;
    scanf("%d %d",&r,&c);
    ans = (double)(r-c)*(r-c)/r/r;
    printf("%.6lf\n",ans*100);
    return 0;
}