// Meysam Aghighi

#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct object {
    int v; // value
    int w; // weight
};

int main(){
    double C;
    int n,c;
    int sol[2001][2001];
    bool mark[2001][2001];
    object a[2001];

//    while (cin>>C>>n){
    while (scanf("%lf %d",&C,&n)==2){
        c = C;
        memset(mark,false,sizeof(mark));
        for (int i=0;i<n;i++)
            scanf("%d %d",&a[i+1].v,&a[i+1].w);

        for (int j=0;j<=c;j++)
            sol[0][j] = 0;

        for (int i=1;i<=n;i++)
            for (int j=0;j<=c;j++){
                if (a[i].w <= j && sol[i-1][j] < sol[i-1][j-a[i].w] + a[i].v){
                    sol[i][j] = sol[i-1][j-a[i].w] + a[i].v;
                    mark[i][j] = true;
                }
                else
                    sol[i][j] = sol[i-1][j];
            }
        // try with set
        set <int> final_sol;
        int ii=n , jj=c;
        while(ii && jj){
            if (mark[ii][jj]){
                final_sol.insert(ii-1);
                jj -= a[ii].w;
            }
            ii--;
        }

        // try with printf
        printf("%d\n",final_sol.size());
        for (set<int>::iterator it=final_sol.begin(); it!=final_sol.end(); ++it)
            printf("%s%d",(it!=final_sol.begin()?" ":""),*it);
        printf("\n");

//        cout << final_sol.size() << endl;
//        for (set<int>::iterator it=final_sol.begin(); it!=final_sol.end(); ++it)
//            cout << (it!=final_sol.begin()?" ":"") << *it;
//        cout << endl;


//        vector <int> final_solution;
//        int ii=n , jj=c;
//        while(ii && jj){
//            if (mark[ii][jj]){
//                final_solution.push_back(ii-1);
//                jj -= a[ii].w;
//            }
//            ii--;
//        }
//        sort(final_solution.begin(),final_solution.end());
//        cout << final_solution.size() << endl;
//        for (int i=0;i<final_solution.size();i++)
//            cout << (i?" ":"") << final_solution[i];
//        cout << endl;
    }
    return 0;
}
