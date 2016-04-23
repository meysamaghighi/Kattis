// Meysam Aghighi

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int n;
    cin >> n;
    int u[n],v[n]; // n places
    bool mark[n+1]; // real values
    memset(mark,0,sizeof(mark));
    int head = n+1;
    for (int i=0;i<n;i++)
//        cin >> v[i];
        scanf("%d",&v[i]);
    if (v[n-1]==n+1){
        for (int i=n-1;i>=1;i--){
            if (!mark[v[i-1]] && v[i-1]<n+1){
                u[i] = v[i-1];
                mark[v[i-1]] = true;
            }
            else {
//                cout << "head = " << head << endl;
                do {
                  head--;
                } while(mark[head]);
//                cout << "head = " << head << endl;
                u[i] = head;
                mark[head++] = true;
            }
        }
        do {head--;} while (mark[head]);
        u[0] = head;
        for (int i=0;i<n;i++)
//            cout << u[i] << endl;
            printf("%d\n",u[i]);
    }
    else cout << "Error" << endl;
    return 0;
}
