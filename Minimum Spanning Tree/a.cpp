// Meysam Aghighi

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge{
	int u,v,w;
	edge (int _u, int _v, int _w) { u = _u, v = _v, w = _w;}
	bool operator < (edge e) const { return w > e.w; }
};

int main(){
	int n,m,u,v,w;
	while (cin>>n>>m && n){
		vector<edge> g[n]; // graph
		for (int i=0;i<m;i++){
			cin >> u >> v >> w;
			g[u].push_back(edge(u,v,w));
			g[v].push_back(edge(v,u,w));
		}
		// Prim (MST)
		priority_queue<edge> q;
		vector<edge> mst;
		bool marked[n]; memset(marked,false,sizeof(marked));
		long long sum = 0;
		marked[0] = true;
		for (int i=0;i<g[0].size();i++) q.push(g[0][i]);
		while (mst.size() < n-1 && !q.empty()){
//			for (int i=0;i<q.size();i++) cout << q[i].u << " " << q[i].v << endl;
			edge e = q.top(); q.pop();
			u = e.u;
			v = e.v;
			w = e.w;
//			cout << "first: " << u << " " << v << " " << w << endl;
			if (marked[u] && marked[v]) continue;
			if (marked[u]){
				for (int i=0;i<g[v].size();i++) q.push(g[v][i]);
			}
			if (marked[v]){
				for (int i=0;i<g[u].size();i++) q.push(g[u][i]);
			}
//			cout << "second: " << u << " " << v << " " << w << endl;
			marked[u] = marked[v] = true;
			mst.push_back(e);
			sum += w;
		}
		if (mst.size() == n-1){
				cout << sum << endl;
				pair<int,int> a[n-1];
				for (int i=0;i<n-1;i++) a[i].first = min(mst[i].u,mst[i].v), a[i].second = max(mst[i].u,mst[i].v);
				sort(a,a+(n-1));
				for (int i=0;i<n-1;i++) cout << a[i].first << " " << a[i].second << endl;
//				for (int i=0;i<mst.size();i++) cout << mst[i].u << " " << mst[i].v << endl;
		}
		else cout << "Impossible" << endl;
	}
	return 0;
}
