// Meysam Aghighi

#include <iostream>
using namespace std;

int main(){
    long long n,x;
    int twos = 0 , fives = 0;
    cin >> n;
    long long fact = 1;
    for (long long i=2;i<=n;i++){
        x = i;
        while (x%5 == 0){
            x /= 5;
            fives++;
        }
        while (x%2 == 0){
            x /= 2;
            twos++;
        }
        fact = (fact * x) % 1000;
    }
    int pow = (twos-fives);
    while (pow--){
        fact = (fact*2)%1000;
    }
    if (n > 6 && fact < 100){
        if (fact < 10)
            cout << "00" << fact << endl;
        else cout << "0" << fact << endl;
    }
    else cout << fact << endl;
    return 0;
}
