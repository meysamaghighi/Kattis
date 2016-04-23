// Meysam Aghighi
#include <iostream>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

struct clause {
    int x[20];
    clause (){}
    clause (int v){
        for (int i=0;i<20;i++) x[i] = v;
    }
};

template <size_t N>
std::bitset<N> increment ( std::bitset<N> in ) {
    for ( size_t i = 0; i < N; ++i ) {
        if ( in[i] == 0 ) {  // There will be no carry
            in[i] = 1;
            break;
            }
        in[i] = 0;  // This entry was 1; set to zero and carry the 1
        }
    return in;
}

clause parse(string s){
    stringstream ss(s);
    clause c(0);
    int i = 0;
    stringstream temp;
    while (ss >> s){
        if (s[0] == 'X'){
            c.x[i++] = atoi(s.substr(1,s.size()-1).c_str());
        }
        else if (s[0] == '~'){
            c.x[i++] = -atoi(s.substr(2,s.size()-2).c_str());
        }        
    }
    return c;
}

template <size_t N>
bool check(bitset<N> foo, clause c){
    int x[20];
    for (int i=0;i<20;i++) x[i] = c.x[i];
    bool b = false;
    for (int i=0;i<20;i++){
        if ( (x[i] > 0 && foo[x[i]-1]) || (x[i] < 0 && !foo[-x[i]-1]) ){
            b = true;
        }
    }
    return b;
}

int main(){
    int t , n , m;
    string s;
    cin >> t;
    while (t--){
        cin >> n >> m;
        clause c[m];
        getline(cin,s);
        for (int i=0;i<m;i++){
            getline(cin,s);
            c[i] = parse(s);
            // cerr << c[i].x[0] << " " << c[i].x[1] << " " << c[i].x[2] << endl;            
        }
        bitset<20> foo; // all 0 by default
        bool sat = true;
        for (int i=0;i<pow(2,n);i++,foo = increment(foo)){
            sat = true;
            for (int j=0;j<m;j++){
                if (!check(foo,c[j])){
                    sat = false;
                    break;
                }
            }
            if (sat){
                cout << "satisfiable" << endl;
                break;
            }
        }
        if (!sat) cout << "unsatisfiable" << endl;        
    }
    return 0;
}