// Meysam Aghighi

#include <iostream>
#include <cstdio>
using namespace std;

class QuickUnion {
private:
    int * id;
    int * rank;
public:
    QuickUnion (int N) {
        id = new int[N];
        rank = new int[N];
        for (int i = 0; i < N; i++){
            id[i] = i;
            rank[i] = 0;
        }
    }
    int root(int i){
        while (i != id[i])
            i = id[i];
        return i;
    }
    bool find(int p, int q){
        return root(p) == root(q);
    }
    void uni(int p, int q){
        int i = root(p);
        int j = root(q);
        if (i == j)
            return;

        if (rank[i] < rank[j])
            id[i] = j;
        else if (rank[i] > rank[j])
            id[j] = i;
        else {
            id[j] = i;
            rank[i] = rank[i] + 1;
        }
    }
};

int main(){
    int n,q,a,b;
    char c[2];
    scanf("%d%d",&n,&q);
    QuickUnion * meysam = new QuickUnion(n);
    while(q--){
        scanf("%2s%d%d",c,&a,&b);
        if (c[0] == '=') meysam->uni(a,b);
        else if (meysam->find(a,b)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
