// Meysam Aghighi

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

typedef unsigned long long LONG;

struct fraction {
    LONG a;
    LONG b;

    fraction (){}

    fraction (LONG _a, LONG _b){
        a = _a;
        b = _b;
    }
};

LONG gcd (LONG a,LONG b){
  return (a == 0 ? b : gcd(b % a , a));
}

fraction add (fraction m, fraction n){
    LONG a = m.a*n.b + m.b*n.a;
    LONG b = m.b*n.b;
    LONG d = gcd(a,b);
    a /= d;
    b /= d;
    return fraction(a,b);
}

fraction f(string s, int t){
    fraction x,y,current(1,999999999999999999LL),temp;
    for(int l=2;l<t;l++){ // l is the start of repeating, t-1 is the end of repeating
        LONG makhraj = pow(10,l-2);
        LONG soorat = 0;
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
//        cerr << x.a << "/" << x.b << " & " << y.a << "/" << y.b << endl;
    }
    return current;
}

int main(){
    string s;
    fraction answer;
    while (getline(cin,s)){
        size_t found = s.find("..");
        if (found != std::string::npos)
            answer = f(s,found);
        else break;
        cout << answer.a << "/" << answer.b << endl;
    }
    return 0;
}
