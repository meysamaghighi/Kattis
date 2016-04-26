// Meysam Aghighi

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

struct fraction {
    ull a,b;
    fraction (){}
    fraction (ull _a, ull _b): a(_a), b(_b){}
};

ull gcd(ull a, ull b){ return (a == 0 ? b : gcd(b % a , a)); }

fraction add (fraction m, fraction n){
    ull a = m.a*n.b + m.b*n.a;
    ull b = m.b*n.b;
    ull d = gcd(a,b);
    a /= d;
    b /= d;
    return fraction(a,b);
}

fraction f(string s, int t){
    fraction x,y,current(1,999999999999999999LL),temp;
    for(int l=2;l<t;l++){ // l is the start of repeating, t-1 is the end of repeating
        ull makhraj = pow(10,l-2);
        ull soorat = 0;
        for (int i=2;i<l;i++)
            soorat = soorat*10 + (s[i]-'0');
        x.a = soorat;
        x.b = makhraj;
        soorat = 0;
        for (int i=l;i<t;i++)
            soorat = soorat*10 + (s[i]-'0');
        y.a = soorat;
        y.b = (pow(10,t-l)-1)*makhraj;
        temp = add(x,y);
        if (temp.b < current.b)
            current = temp;
    }
    return current;
}

int main(){
    string s;
    fraction answer;
    while (getline(cin,s)){
        size_t found = s.find("..");
        if (found != std::string::npos) answer = f(s,found);
        else break;
        cout << answer.a << "/" << answer.b << endl;
    }
    return 0;
}
