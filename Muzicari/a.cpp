// Meysam Aghighi
// Variation of knapsack - instead of assigning total value to each state we assign the negative empty space
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int sol[510][5010];
bool mark[510][5010];

int main(){
	int c,n;
	memset(mark,false,sizeof(mark));	
	cin >> c >> n;
	int b[n];
	for (int i=0;i<n;i++) cin >> b[i];
	for (int j=0;j<=c;j++) sol[0][j] = -j;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=c;j++){
            if (b[i-1] <= j && sol[i-1][j] - 1 < sol[i-1][j-b[i-1]]){
                sol[i][j] = sol[i-1][j-b[i-1]];
                mark[i][j] = true;
            }
            else
                sol[i][j] = sol[i-1][j] - 1;
        }
    vector<int> belong(n,0);
    int ii=n , jj=c;
    while(ii && jj){
        if (mark[ii][jj]){
            belong[ii-1] = 1;
            jj -= b[ii-1];
        }
        ii--;
    }
    // musicians rest in two queues: one & two
    int one = 0, two = 0;
    for (int i=0;i<n;i++){
        if (belong[i] == 1){ // one
            cout << one;
            one += b[i];
        }
        else { // two
            cout << two;
            two += b[i];
        }
        if (i < n-1) cout << " ";
        else cout << endl;
    }

	return 0;
}
