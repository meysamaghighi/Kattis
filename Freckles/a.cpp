// Meysam Aghighi

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct edge{
	int u,v;
        double w;
	edge (int _u, int _v, double _w) { u = _u, v = _v, w = _w;}
	bool operator < (edge e) const { return w > e.w; }
};

double x[1010], y[1010];

double dist(int i, int j){
    double xx = x[i] - x[j] , yy = y[i] - y[j];
    return sqrt(xx*xx + yy*yy);
}

int main(){
	int N,n,u,v;
        double d;
	cin >> N;
	while (N--){            
            cin >> n;            
            for (int i=0;i<n;i++) cin >> x[i] >> y[i];
            vector<edge> g[n];
            for (int i=0;i<n;i++){
                for (int j=i+1;j<n;j++){                    
                    d = dist(i,j);
                    g[i].push_back(edge(i,j,d));
                    g[j].push_back(edge(j,i,d));                    
                }
            }

            // Prim (MST)
            priority_queue<edge> q;
            bool marked[n]; memset(marked,false,sizeof(marked));
            double sum = 0;
            int t = 0;
            marked[0] = true;
            for (int i=0;i<g[0].size();i++) q.push(g[0][i]);
            while (t < n-1 && !q.empty()){
                    edge e = q.top(); q.pop();
                    u = e.u;
                    v = e.v;
                    d = e.w;
                    if (marked[u] && marked[v]) continue;
                    if (marked[u]){
                            for (int i=0;i<g[v].size();i++) q.push(g[v][i]);
                    }
                    if (marked[v]){
                            for (int i=0;i<g[u].size();i++) q.push(g[u][i]);
                    }
                    marked[u] = marked[v] = true;
                    sum += d;
                    t++;
            }
//            cout << setprecision (2) << sum << endl;
            printf("%.2lf\n",sum);
            if (N) cout << endl;
	}
	return 0;
}
