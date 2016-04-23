// Meysam Aghighi
// Use a Trie for the dictionary and then search every combination of elementary changes.
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// trie -- from SuprDewd
template <class T>
struct trie {
    struct node {
        map<T, node*> children;
        int prefixes, words;
        node() { prefixes = words = 0; }
    };
    node* root;
    trie() : root(new node()) {  }
    template <class I>
    void insert(I begin, I end) {
        node* cur = root;
        while (true) {
            cur->prefixes++;
            if (begin == end) { cur->words++; break; }
            else {
                T head = *begin;
                typename map<T, node*>::const_iterator it;
                it = cur->children.find(head);
                if (it == cur->children.end()) {
                    pair<T, node*> nw(head, new node());
                    it = cur->children.insert(nw).first;
                } begin++, cur = it->second;
            }
        }
    }
    template<class I>
    int countMatches(I begin, I end) {
        node* cur = root;
        while (true) {
            if (begin == end) return cur->words;
            else {
                T head = *begin;
                typename map<T, node*>::const_iterator it;
                it = cur->children.find(head);
                if (it == cur->children.end()) return 0;
                begin++, cur = it->second;
            }
        }
    }
};

bool check(trie<char> &t, string s, int steps, int digits){
    // cerr << s << endl;
    if (steps < digits) return false;
    if (steps == 0) return (bool)t.countMatches(s.begin(), s.end());
    if (t.countMatches(s.begin(), s.end())) return true;
    if (digits){
        for (int i=0;i<s.size();i++){
            if (isdigit(s[i])){
                for (s[i] = 'a'; s[i] <= 'z'; s[i]++){                                        
                    if (check(t, s, steps-1, digits-1)) return true;                    
                }
                for (s[i] = 'A'; s[i] <= 'Z'; s[i]++){
                    if (check(t, s, steps-1, digits-1)) return true;
                }
            }
        }
    }
    else {
        for (int i=0; i<s.size()-1; i++){
            swap(s[i], s[i+1]);
            if (check(t, s, steps-1, digits)) return true;
            swap(s[i], s[i+1]);
        }
    }
    return false;
}

int main(){
    int n;
    string s;
    cin >> n;
    trie <char> t;
    while (n--){
        cin >> s;
        t.insert(s.begin() , s.end());
    }
    while (cin >> s){
        int digits = 0;
        for (int i=0;i<s.size();i++) if (isdigit(s[i])) digits++;                
        if (!check(t,s,3,digits)) cout << s << endl;        
    }       
    return 0;
}