// Meysam Aghighi
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

vector<string> dic;
map <string,int> cache;

void computeLPSArray(string pat, int *lps){
    int len = 0;
    int i = 1; 
    lps[0] = 0; 
    while (i < pat.size()){
       if (pat[i] == pat[len]){
         len++;
         lps[i] = len;
         i++;
       }
       else{       
         if (len != 0) len = lps[len-1];
         else lps[i] = 0, i++;
       }
    }
}

int findFirst(string pat, string txt){
    int M = pat.size();
    int N = txt.size(); 
    int * lps = new int[M];
    int j  = 0 , i = 0;
 
    computeLPSArray(pat, lps);

    while (i < N){
      if (pat[j] == txt[i]) i++ , j++;
 
      if (j == M){
        // cout << i-j << " ";
        return i-j;
        j = lps[j-1];
      }
 
      else if (i < N && pat[j] != txt[i]){
        if (j != 0) j = lps[j-1];
        else i++;
      }
    }
    
    return -1;
}

int solve(string s){
    // cerr << s << endl;
    if (s.size() == 0) return 0;
    if (cache.count(s)) return cache[s];
    int ans = 0;
    for (int i=0;i<dic.size();i++){
        int it = findFirst(dic[i],s);
        // cerr << dic[i] << " " << s << " : " << it << endl;
        if (it != -1) ans = max( ans , 1 + solve(s.substr(0,it)) + solve(s.substr(it+dic[i].size(),s.size()-it-dic[i].size())) );
    }
    return cache[s] = ans;
}

int main(){
    string s,t;
    while (cin >> s && s[0] != '#') dic.push_back(s);    
    while (cin >> s && s[0] != '#'){
        while (s[s.size()-1] != '|') {
            cin >> t;
            s.append(t);
        }
        s = s.substr(0,s.size()-1);
        // s is ready        
        cout << solve(s) << endl;        
    }
    
    return 0;
}