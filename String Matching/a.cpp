// Meysam Aghighi
// KMP String Search
#include <iostream>
#include <cstring>
using namespace std;

void computeLPS(string pat, int *lps){
    int len = 0, i = 1;
    lps[0] = 0; 
    while (i < pat.size()){
       if (pat[i] == pat[len]) lps[i++] = ++len;
       else{       
         if (len != 0) len = lps[len-1];
         else lps[i] = 0, i++;
       }
    }
}

void KMP(string pat, string txt){
    int M = pat.size(), N = txt.size(); 
    int lps[M];
    int j  = 0 , i = 0;
 
    computeLPS(pat, lps);

    while (i < N){
      if (pat[j] == txt[i]) i++ , j++;
      if (j == M){
        cout << i-j << " ";
        j = lps[j-1];
      } 
      else if (i < N && pat[j] != txt[i]){
        if (j != 0) j = lps[j-1];
        else i++;
      }
    }
    cout << endl;
}
 
int main(){
    string pat , txt;
    while (getline(cin,pat) && getline(cin,txt)) KMP(pat,txt);
    return 0;
}
