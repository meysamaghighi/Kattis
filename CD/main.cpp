#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m,a;
    vector<int>::iterator it;
    int answer;
    while(true){
        vector <int> jack;
        answer = 0;
        cin >> n;
        cin >> m;
        if(n==0)
            break;
        for (int i=0;i<n;i++){
            cin >> a;
            jack.push_back(a);
        }
        it = jack.begin();
        
        for (int i=0;i<m;i++){
            cin >> a;
            do{
                if(*it == a)
                    answer++;
                it++;
            } while(*it <= a && it <= jack.end());
            it--;
        }
        cout << answer << endl;
    }
    return 0;
}
