// Meysam Aghighi

#include <iostream>
using namespace std;

// bad numbers: 3 4 7
//1 -> 1
//2 -> 2
//5 -> 5
//6 -> 9
//8 -> 8
//9 -> 6
//0 -> 0
bool valid (int n){
    int x;
    while(n>1){
        x = n%10;
        if (x==3 || x==4 || x==7)
            return false;
        n = n/10;
    }
    return true;
}

void print (int n){
    int x;
    while (n>0){
        x = n%10;
        if (x == 6)
            cout << 9;
        else if (x == 9)
            cout << 6;
        else cout << x;
        n = n/10;
    }
    cout << endl;
}

int main(){
//    int n;
//    while(cin>>n){
//        cout << valid(n) << endl;
//    }

    int it = 1 , i = 1;
    int MAX = 1000000;
    long long a[MAX];
    while (it<MAX){
        if (valid(i))
            a[it++] = i;
        i++;
    }
    for (int i=1;i<10001;i++)
        print(a[i]);
//    int n;
//    while (cin>>n){
//        print(a[n]);
//    }
    return 0;
}
