// Meysam Aghighi
// Modified version of kmp algorithm from geeksforgeeks.org
#include <iostream>
#include <cstring>
using namespace std;

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

void KMPSearch(string pat, string txt){
    int M = pat.size();
    int N = txt.size(); 
    int * lps = new int[M];
    int j  = 0 , i = 0;
 
    computeLPSArray(pat, lps);

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
    while (getline(cin,pat) && getline(cin,txt)) KMPSearch(pat,txt);
    return 0;
}