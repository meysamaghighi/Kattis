// Meysam Aghighi

#include <cstdio>
using namespace std;

int N,Q,i;
char c;
long long BIT[5000001],delta;

inline void update(int x, long long val)
{
    for(; x <= N; x += x&-x){
        BIT[x] += val;
    }
}
inline long long query(int x)
{
     long long sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main(){
    scanf("%d%d",&N,&Q);
    while (Q--){
        scanf(" %c ",&c);
        if (c=='+'){
            scanf("%d%lld",&i,&delta);
            update(i+1,delta);
        }
        else {
            scanf("%d",&i);
            if(i) printf("%lld\n",query(i));
            else printf("0\n");
        }
    }
    return 0;
}
