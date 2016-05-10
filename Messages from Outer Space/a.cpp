// Meysam Aghighi
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<string> dic;
map <int,int> cache;

#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef vector<vector<int> > vvi;
map<string,int> all;
vvi res;
string s;

// Aho-Corasick from SuprDewd
struct aho_corasick {
    struct out_node {
        string keyword; out_node *next;
        out_node(string k, out_node *n) : keyword(k), next(n) { }
    };
    struct go_node {
        map<char, go_node*> next;
        out_node *out; go_node *fail;
        go_node() { out = NULL; fail = NULL; }
    };
    go_node *go;
    int N;
    aho_corasick(vector<string> keywords) {
        N = keywords.size();
        go = new go_node();
        iter(k, keywords) {
            go_node *cur = go;
            iter(c, *k)
                cur = cur->next.find(*c) != cur->next.end() ? cur->next[*c] :
                    (cur->next[*c] = new go_node());
            cur->out = new out_node(*k, cur->out);
        }
        queue<go_node*> q;
        iter(a, go->next) q.push(a->second);
        while (!q.empty()) {
            go_node *r = q.front(); q.pop();
            iter(a, r->next) {
                go_node *s = a->second;
                q.push(s);
                go_node *st = r->fail;
                while (st && st->next.find(a->first) == st->next.end())
                    st = st->fail;
                if (!st) st = go;
                s->fail = st->next[a->first];
                if (s->fail) {
                    if (!s->out) s->out = s->fail->out;
                    else {
                        out_node* out = s->out;
                        while (out->next) out = out->next;
                        out->next = s->fail->out;
                    }
                }
            }
        }
    }
    vvi search(string s){
        vvi ress(N);
        go_node *cur = go;
        iter(c, s) {
            while (cur && cur->next.find(*c) == cur->next.end())
                cur = cur->fail;
            if (!cur) cur = go;
            cur = cur->next[*c];
            if (!cur) cur = go;
            for (out_node *out = cur->out; out; out = out->next){
                ress[all[out->keyword]].push_back(c-s.begin()-out->keyword.size()+1);
            }
        }
        return ress;
    }
};

int solve(int p){
    if (s.size() == p) return 0;
    if (cache.count(p)) return cache[p];
    int ans = 0;
    for (int i=0;i<dic.size();i++){
        vector<int> &ac = res[all[dic[i]]];
        int it = -1;
        for (int j=0;j<ac.size();j++){
            if (ac[j] >= p){
                it = ac[j];
                break;
            }
        }
        if (it != -1) ans = max( ans , 1 + solve(it + dic[i].size()) );
    }
    return cache[p] = ans;
}

int main(){
    string t;
    int i = 0;
    while (cin >> s && s[0] != '#'){
        dic.push_back(s);
        all[s] = i++;   
    }
    while (cin >> s && s[0] != '#'){
        while (s[s.size()-1] != '|') {
            cin >> t;
            s.append(t);
        }
        s = s.substr(0,s.size()-1);
        // s is ready
        aho_corasick AC(dic);
        cache.clear();
        res = AC.search(s);  
        cout << solve(0) << endl;        
    }
    
    return 0;
}