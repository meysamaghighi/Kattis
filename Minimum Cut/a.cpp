// Meysam Aghighi

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <stack>
using namespace std;

#define N 505
int n,m,s,t,u,v,w;
long long g[N][N], rg[N][N], f[N], max_flow, path_flow;
int p[N];

long long bfs(int s, int t){
    bool visited[n]; memset(visited,false,sizeof(visited)); visited[s] = true;
    queue <int> q; q.push(s);
    p[s] = -1; // needed?
    f[s] = INT_MAX;
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v=0; v<n; v++){
            if (visited[v]==false && rg[u][v] > 0){
                q.push(v);
                p[v] = u;
                visited[v] = true;
                f[v] = min(f[u],rg[u][v]);
            }
        }
    }
    return (visited[t]?f[t]:0);
}


void MinCut(int s, int t){
	// Edmond-karp (max-flow)
//    max_flow = 0;
    while (path_flow = bfs(s, t)){
        for (v=t; v != s; v=p[v]){
            u = p[v];
            rg[u][v] -= path_flow;
            rg[v][u] += path_flow;
        }
//        max_flow += path_flow;
    }

    // DFS from s in rg
    int total = 0;
    stack<int> ss; ss.push(s);
    bool marked[n]; memset(marked,false,sizeof(marked));
    while(!ss.empty()){
    	int i = ss.top(); ss.pop();
    	marked[i] = true; total++;
    	for (int j=0;j<n;j++)
    		if (rg[i][j] > 0 && !marked[j]){
    			marked[j] = true;
    			ss.push(j);    	
    		}
    }
    // Print output
    cout << total << endl;
    for (int i=0;i<n;i++) if (marked[i]) cout << i << endl;

}

int main(){
	cin >> n >> m >> s >> t;
	memset(g,0,sizeof(g));
	memset(rg,0,sizeof(rg));
	for (int i=0;i<m;i++){
		cin >> u >> v >> w;
		g[u][v] = rg[u][v] = w;
	}
	MinCut(s,t);
	return 0;
}
