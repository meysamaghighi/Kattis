#include <iostream>
#include <cstring>
using namespace std;

char alpha[] = "abcdefghijklmnopqrstuvwxyz";

inline int IsAlpha( char c )
{
   char * a = strchr(alpha,tolower(c));
   if (a != NULL)
       return a-alpha;
   else return -1;
}

int main(){
    int n,temp;
    bool pangram;
    bool *a;
    string s;
    cin >> n;
    getline(cin,s);
    for (int i=0;i<n;i++){
        a = new bool[26]();
        getline(cin,s);
        for (int j=0;j<s.size();j++){
            temp = IsAlpha(s.at(j));
            if (temp != -1)
                a[temp] = true;
        }
        pangram = true;
        for (int j=0;j<26;j++){
            if (!a[j])
                pangram = false;
        }
        if (pangram)
            cout << "pangram" << endl;
        else {
            cout << "missing ";
            for (int j=0;j<26;j++)
                if (!a[j])
                    cout << alpha[j];
            cout << endl;
        }
    }
    return 0;
}