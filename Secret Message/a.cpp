#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        int k = ceil(sqrt(s.size()));
        string temp (k*k-s.size(),'*');
        s.append(temp);
        //cout << s << endl;
        string ss;
        for (int j=0;j<k;j++)
            for (int i=k-1;i>=0;i--)
                ss.push_back(s.at(k*i+j));
        //cout << ss << endl;
        for (int i=0;i<ss.size();i++)
            if (ss.at(i)=='*'){
                ss.erase(ss.begin()+i);
                i--;
            }
        cout << ss << endl;
    }
	
	return 0;
}

