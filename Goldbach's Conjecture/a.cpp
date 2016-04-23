#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
using namespace std;

#define N 1000010

bitset<N> pp;
int x;

void init(){
    for (int i=2;i<1011;i++){
        if (!pp[i]){
            x = i*i;
            while (x < N){
                pp[x] = 1;
                x += i;
            }
        }
    }
}

int main(){
    init();
    pp[1] = 1;
    // Going for Goldbach
    int n,a;
    cin >> n;
    for (int i=0;i<n;i++){
            cin >> a;
            vector <int> answer;
            for (int j=2;j<=a/2;j++){
                if (!pp[j] && !pp[a-j]){
                    answer.push_back(j);
                }
            }
            cout << a << " has " << answer.size() << " representation(s)\n";
            for (int j=0;j<answer.size();j++){
                cout << answer[j] << "+" << a-answer[j] << "\n";
            }
            cout << "\n";
    }    return 0;
}