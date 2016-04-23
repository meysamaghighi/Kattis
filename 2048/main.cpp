#include <iostream>
#include <vector>
using namespace std;

void print(int *a[], int d){
    switch(d){
        case 0:
            for (int i=0;i<4;i++){
                for (int j=0;j<3;j++)
                    cout << a[i][j] << " ";
                cout << a[i][3] << endl;
            }
            break;
        case 1:
            for (int j=0;j<4;j++){
                for (int i=0;i<3;i++)
                    cout << a[i][j] << " ";
                cout << a[3][j] << endl;
            }
            break;
        case 2:
            for (int i=0;i<4;i++){
                for (int j=0;j<3;j++)
                    cout << a[i][3-j] << " ";
                cout << a[i][0] << endl;
            }
            break;
        case 3:
            for (int j=3;j>=0;j--){
                for (int i=0;i<3;i++)
                    cout << a[i][j] << " ";
                cout << a[3][j] << endl;
            }
            break;
    }
}

int* fix(int a[]){
    vector <int> aa;
    for (int i=0;i<4;i++)
        if (a[i] != 0)
            aa.push_back(a[i]);
    if (aa.size()>0)
        for (int i=0;i<aa.size()-1;i++){
            if (aa.at(i) == aa.at(i+1)){
                aa[i] = 2*aa[i];
                aa.erase(aa.begin()+i+1);
            }
        }
    int *b;
    b = new int[4]();
    for (int i=0;i<aa.size();i++)
        b[i] = aa.at(i);
    return b;   
}

int main(){
    int *a[4];
    int *b[4];
    for (int i=0;i<4;i++){
        b[i] = new int[4]();
        a[i] = new int[4]();
    }
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            cin >> a[i][j];
    int d;
    cin >> d;
    switch (d){
        case 0: //left
            for (int i=0;i<4;i++)
                b[i] = fix(a[i]);
            break;
        case 1: //up
            for (int i=0;i<4;i++){
                int temp[4] = {a[0][i],a[1][i],a[2][i],a[3][i]};
                b[i] = fix(temp);
            }
            break;
        case 2: //right
            for (int i=0;i<4;i++){
                int temp[4] = {a[i][3],a[i][2],a[i][1],a[i][0]};
                b[i] = fix(temp);
            }
            break;
        case 3: //down
            for (int i=0;i<4;i++){
                int temp[4] = {a[3][i],a[2][i],a[1][i],a[0][i]};
                b[i] = fix(temp);
            }
            break;
    }
    print(b,d);
           
    return 0;
}