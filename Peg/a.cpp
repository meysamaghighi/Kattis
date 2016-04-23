// Meysam Aghighi

#include <iostream>
using namespace std;

int main(){
    int a[7][7] = {0}; // board
//    int ii,jj; // . position
    char c;
    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
            cin >> noskipws >> c;
            switch (c){
            case ' ': a[i][j] = -1;
                break;
            case 'o': a[i][j] = 1;
                break;
            case '.': a[i][j] = 0;
                break;
            }
        }
        cin >> noskipws >> c;
    }

    // check 4 direction for each . cell
    int answer = 0;
    for (int i=0;i<7;i++)
        for (int j=0;j<7;j++)
            if (a[i][j] == 0){
                if (j>=2)
                    if (a[i][j-1]==1 && a[i][j-2]==1)
                        answer++;
                if (j<=4)
                    if (a[i][j+1]==1 && a[i][j+2]==1)
                        answer++;
                if (i>=2)
                    if (a[i-1][j]==1 && a[i-2][j]==1)
                        answer++;
                if (i<=4)
                    if (a[i+1][j]==1 && a[i+2][j]==1)
                        answer++;
            }


    cout << answer << endl;


//    for (int i=0;i<7;i++){
//        for (int j=0;j<7;j++)
//            cout << a[i][j];
//        cout << endl;
//    }
    return 0;
}
