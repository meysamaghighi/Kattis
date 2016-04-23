#include <iostream>
using namespace std;

int main(){
    int a[8][8];
    char x;
    for (int i=0;i<8;i++)
        for (int j=0;j<8;j++){
            cin >> x;
            if (x == '*')
                a[i][j] = 1;
        }
    for (int i=0;i<8;i++)
        for (int j=0;j<8;j++){

        }
    return 0;
}
