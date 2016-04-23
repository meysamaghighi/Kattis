// Meysam Aghighi

#include <iostream>
#include <cstring>
using namespace std;

const int UP=1,DOWN=-1;

int main(){
    int N,M,up,down;
    cin >> N;
    while (N--){
        cin >> M;
        int d[M+1];
        int a[41][1001];
        memset(a, -1, sizeof(a[0][0])*41*1001);
        int dir[41][1001] = {0};
        for (int i=1;i<=M;i++)
            cin >> d[i];
//        for (int i=0;i<10;i++){
//            for (int j=0;j<10;j++)
//                cout << a[i][j] << " ";
//            cout << endl;
//        }
        a[0][0] = 0;
        for (int i=1;i<=M;i++){
            for (int j=0;j<=1000-d[i];j++){
                up = j + d[i];
                down = j - d[i];
                if (down >= 0){
                    if (a[i-1][up] != -1 && a[i-1][down] != -1){
                        a[i][j] = min( a[i-1][up] , max(j , a[i-1][down]) );
                        dir[i][j] = (a[i-1][up] > max(j , a[i-1][down]) ? UP : DOWN);
                    }
                    else if (a[i-1][up] != -1){
                        a[i][j] = a[i-1][up];
                        dir[i][j] = DOWN; // we move down to reach a[i][j]
                    }
                    else if (a[i-1][down] != -1){
                        a[i][j] = max(j , a[i-1][down]);
                        dir[i][j] = UP; // we move up to reach a[i][j] from a[i-1][]
                    }
                }
                else if (a[i-1][up] != -1){
                    a[i][j] = a[i-1][up];
                    dir[i][j] = DOWN;
                }
            }
        }
        int sol[M+1];
        int pos = 0;
        for (int i=M;i>=1;i--){
            sol[i] = dir[i][pos];
            pos = pos - dir[i][pos]*d[i];
        }
        if (a[M][0] != -1){
            for (int i=1;i<=M;i++)
                cout << (sol[i]==UP?"U":"D");
            cout << endl;
        }
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
