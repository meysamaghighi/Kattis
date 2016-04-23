// Meysam Aghighi

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(){
    int n,m,c,a,b,r,r1,r2;
    long long sum;
    while(scanf("%d%d",&n,&m) == 2){
        set <int> sets[n];
        int place[n];
        for (int i=0;i<n;i++){
            sets[i].insert(i);
            place[i] = i;
        }
        while(m--){
            scanf("%d%d",&c,&a);a--;
            if (c == 3){
                r = place[a];
                sum = 0;
                for (set<int>::iterator it=sets[r].begin();it!=sets[r].end();++it)
                    sum += *it+1;
                printf("%lu %lld\n",sets[r].size(),sum);
            }
            else {
                scanf("%d",&b);b--;
                if (c == 1){ // union
                    r1=place[a],r2=place[b];
                    if (r1 == r2) continue;
                    if (sets[r1].size() < sets[r2].size()){
                        for (set<int>::iterator it=sets[r1].begin();it!=sets[r1].end();++it){
                            sets[r2].insert(*it);
                            place[*it] = r2;
                        }
                        sets[r1].clear();
                    }
                    else {
                        for (set<int>::iterator it=sets[r2].begin();it!=sets[r2].end();++it){
                            sets[r1].insert(*it);
                            place[*it] = r1;
                        }
                        sets[r2].clear();
                    }
                }
                else if (c == 2){ // add
                    r1=place[a],r2=place[b];
                    if (r1 == r2) continue;
                    sets[r1].erase(a);
                    sets[r2].insert(a);
                    place[a] = r2;
                }
            }
        }
    }
    return 0;
}
