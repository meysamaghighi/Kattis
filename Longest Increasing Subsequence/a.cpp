// Meysam Aghighi

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int N,X[100000],P[100000],M[100001],S[100000];
int L, lo, hi, mid, newL, k;

int main(){
    while(scanf("%d",&N)==1){
        for (int i=0;i<N;i++)
            scanf("%d",&X[i]);

        L = 0;

        for (int i=0; i<N;i++){
            // testing
//            for (int ii=0;ii<L;ii++)
//                cout << M[ii+1] << " ";
//            cout << "--------" << endl;
            // Binary search for the largest positive j ≤ L
            // such that X[M[j]] < X[i]
            lo = 1;
            hi = L;
            while (lo <= hi){
                mid = ceil((lo+hi)/2.0);
                if (X[M[mid]] < X[i])
                    lo = mid+1;
                else
                    hi = mid-1;
            }
            // After searching, lo is 1 greater than the
            // length of the longest prefix of X[i]
            newL = lo;

            // The predecessor of X[i] is the last index of
            // the subsequence of length newL-1
            P[i] = M[newL-1];
            M[newL] = i;

            // If we found a subsequence longer than any we've
            // found yet, update L
            if (newL > L)
                L = newL;
        }
        // Reconstruct the longest increasing subsequence
        k = M[L];
        for (int i=L-1;i>=0;i--){
//          S[i] = X[k];
            S[i] = k;
            k = P[k];
        }
        printf("%d\n",L);
        for (int i=0;i<L-1;i++)
            printf("%d ",S[i]);
        printf("%d\n",S[L-1]);

    }
    return 0;
}
