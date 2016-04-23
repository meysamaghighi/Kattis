#include <cstdio>

typedef unsigned long long ULL;

ULL prime(ULL n){		
	for (ULL i=2;i*i<=n;i++)
		if (n % i == 0) return i;
	return n;
}

int main(){
    ULL n;
    while (scanf("%llu",&n)==1 && n){
		if (n == 3) printf("4\n");
		else if (n <= 6) printf("No such base\n");
		else {
			ULL answer = 0;
			for (int i=4;i<=10;i++)
				if (n % i == 3){
					answer = i;
					break;
				}
			ULL p = prime(n-3);
    		if (!answer) answer = (p>3?p:prime((n-3)/p));
    		printf("%llu\n",answer);
    	}
    }
    return 0;
}