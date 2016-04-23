// Meysam Aghighi

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void replace_word(vector<string> &s, string old, string key){
    for (int i=0;i<s.size();i++)
        if (s[i] == old)
            s[i] = key;
}

int main(){
    string a,b;
    string l1,l2;
    getline(cin,a);
    while(getline(cin,l1) && getline(cin,l2)){
        vector <string> s1,s2;        
        istringstream ss1(l1),ss2(l2);
        while(ss1 >> a)
            s1.push_back(a);
        while(ss2 >> b)
            s2.push_back(b);
        if (s1.size() != s2.size()){
            cout << "-\n";
        }
        else{
            int l = s1.size();
            meysam:;
            for (int i=0;i<l;i++){
                if (s1[i][0]=='<' && s2[i][0]!='<'){
                    replace_word(s1,s1[i],s2[i]);
                    goto meysam;
                }
                if (s2[i][0]=='<' && s1[i][0]!='<'){
                    replace_word(s2,s2[i],s1[i]);
                    goto meysam;
                }
            }
            for (int i=0;i<l;i++)
                if (s1[i][0]=='<' && s2[i][0]=='<'){
                    replace_word(s1,s1[i],"a");
                    replace_word(s2,s2[i],"a");
                    goto meysam;
                }            
            
            if (s1==s2){
                for (int i=0;i<l;i++)
                    cout << (i?" ":"") << s1[i];
                cout << '\n';
            }
            else
                cout << "-\n";                
        }       
    }
    return 0;
}


