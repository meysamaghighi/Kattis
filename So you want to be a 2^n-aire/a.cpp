// Meysam Aghighi
// Need to calculate the expected value backwards
#include <cstdio>

int main(){
    int n;
    double t;
    while (scanf("%d %lf",&n,&t)==2 && n){
        double w[n+1]; // w[i] = money won at after step i
        w[n] = 1<<n;
        for (int i=n-1;i>=0;i--){
            double cut = (1<<i) / w[i+1];
            if (t < cut) w[i] = (cut-t)/(1-t)*(1<<i) + (1-cut)/(1-t)*(cut+1)/2*w[i+1]; // [t,cut]: stay , [cut,1]: continue
            else w[i] = (1+t)/2*w[i+1]; // [t,1]: continue
        }
        printf("%.3lf\n",w[0]);
    }
    return 0;
}