// Meysam Aghighi

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct object {
    int ID;
    int next;


    object(int _ID, int _next){
        ID = _ID;
        next = _next;
    }

    bool operator < (object X) const {
        return next < X.next;
    }
};

int main(){
    int c,n,a;
    scanf("%d%d%d",&c,&n,&a);
    int hit[a];
    for (int i=0;i<a;i++)
        scanf("%d",&hit[i]);
    int next_appearance[a];
    int last[n];
    for (int i=0;i<n;i++)
        last[i] = a;
    for (int i=a-1;i>=0;i--){
        next_appearance[i] = last[hit[i]];
        last[hit[i]] = i;
    }
//    for (int i=0;i<a;i++)
//        cout << next_appearance[i] << endl;
//    cout << "====" << endl;
    bool in_cache[n];
    memset(in_cache,false,sizeof(in_cache));
    priority_queue <object> cache;
    int answer = 0;
    int cached = 0;
    for (int i=0;i<a;i++){
//        for (int j=0;j<n;j++)
//            cout << in_cache[j] << endl;
//        cout << ")))))" << endl;
        if (!in_cache[hit[i]]){
            if (cached >= c){ // cache is full, cache.size() may be bigger than "c"
                in_cache[cache.top().ID] = false;
                cache.pop();
            }
            else cached++;
            in_cache[hit[i]] = true;
            answer++;
        }
        cache.push(object(hit[i],next_appearance[i])); // we have to push in any case, to update the next_appearance
    }
    cout << answer << endl;
    return 0;
}
