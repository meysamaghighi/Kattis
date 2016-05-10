// Meysam Aghighi
// Aho-Corasick's algorithm, find keywords' hits in a pattern
using namespace std;
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef vector<vector<int> > vvi;
map<string,int> all;

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

int main(){
    string text;
    int n;
    while (cin >> n){
        all.clear();
        vector<string> keywords;
        getline(cin,text);
        for (int i=0;i<n;i++){
            getline(cin,text);
            keywords.push_back(text);
            all[text] = i;
        }
        getline(cin,text);
        aho_corasick AC(keywords);
        vvi res = AC.search(text);
        for (int i=0;i<n;i++){
            int ii = all[keywords[i]];
            for (int j=0;j<res[ii].size();j++)
                if (!j || (j && res[ii][j] != res[ii][j-1])) cout << res[ii][j] << " "; // if takes care of duplicates
            cout << endl;
        }
    }
   return 0;
}