// Meysam Aghighi
#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool intersect(double x1, double y1, double r1, double x2, double y2, double r2){
    double d =dist(x1,y1,x2,y2); 
    if (d>r1+r2 || abs(d-r1-r2)<EPS) return false; // outside or tangent
    if (abs(d)<EPS && abs(r1-r2)<EPS) return true; // they coincide
    if ( (d+r1 < r2) || (abs(r2-d-r1)<EPS) || (d+r2 < r1) || (abs(r1-d-r2)<EPS) ) return false; // inside or tangent
    return true;
}

int main(){
    int n;
    while (cin >> n && n != -1){ // n can be 0!
        double x[n], y[n], r[n];
        for (int i=0;i<n;i++) cin >> x[i] >> y[i] >> r[i];
        // get the graph
        bool g[n][n];
        memset(g,false,sizeof(g));
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (intersect(x[i],y[i],r[i],x[j],y[j],r[j])) g[i][j] = g[j][i] = true;
            }
        }
        // now we have the graph
        // find the largest component with dfs/bfs
        bool mark[n];
        memset(mark,false,sizeof(mark));
        stack<int> q;
        int best = 0; // largest component
        for (int i=0;i<n;i++){
            if (mark[i]) continue;
            q.push(i);
            int c = 0; // current component
            while (!q.empty()){
                int p = q.top(); q.pop();
                if (mark[p]) continue;
                mark[p] = true;
                c++;
                for (int j=0;j<n;j++){
                    if (g[p][j] && !mark[j]) q.push(j);
                }
            }
            best = max(best,c);
        }
        if (best != 1) cout << "The largest component contains " << best << " rings." << endl;
        else  cout << "The largest component contains " << best << " ring." << endl;
    }
    return 0;
}