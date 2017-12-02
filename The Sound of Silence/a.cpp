// Meysam Aghighi

#include <bits/stdc++.h>

using namespace std;

typedef list<int> LI;

struct MinMaxQueue {
    LI q, qmax, qmin;

    void push(int v) {
        q.push_back(v);

        // every v gets added to or removed from the qmin and qmax lists
        // at most once, hence get amortised O(1) runtime.
        while(!qmax.empty() && qmax.back() < v) qmax.pop_back();
        qmax.push_back(v);
        while(!qmin.empty() && qmin.back() > v) qmin.pop_back();
        qmin.push_back(v);
    }

    int peek() { return q.front(); }

    int pop() {
        int v = q.front();
        q.pop_front();
        if (v == qmax.front()) qmax.pop_front();
        if (v == qmin.front()) qmin.pop_front();
        return v;
    }

    int getMax() { return qmax.front(); }
    int getMin() { return qmin.front(); }
    size_t size() { return q.size(); }
};

int main(){
    int n,m,c,x;
    bool none = true;
    cin >> n >> m >> c;
    MinMaxQueue q;
    for (int i=0;i<n;i++){
        cin >> x;
        q.push(x);
        if (i>=m) q.pop();
        if (i+1>=m && q.getMax()-q.getMin()<=c){
            none = false;
            cout << i+2-m << endl;        
        }
    }
    if (none) cout << "NONE" << endl;
    
    return 0;
}