// Meysam Aghighi

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct edge{
	int u,v,w;
	edge (int _u, int _v, int _w) { u = _u, v = _v, w = _w;}
	bool operator < (edge e) const { return w > e.w; }
};

int main(){
	int N,x,y,u,v,w;
	cin >> N;
	while (N--){
		cin >> x >> y;
		char a[y][x], c;
		vector<pair<int,int> > vertices,g;
		map <int , pair<int,int> > mapp;
		map <pair<int,int> , int > imap;
		int top = 0;
		for (int i=0;i<y;i++) for (int j=0;j<x;j++){
			cin >> noskipws >> c;
			if (c == 'A' || c == 'S'){
				g.push_back(make_pair(i,j));
//				mapp[top++] = make_pair(i,j);
				imap[make_pair(i,j)] = top++;
				vertices.push_back(make_pair(i,j));
			}
			else if (c == ' '){
				g.push_back(make_pair(i,j));
//				mapp[top++] = make_pair(i,j);
				imap[make_pair(i,j)] = top++;
			}
			a[i][j] = c;
		}
		int V = g.size();
		int adj[V][V]; memset(adj,0,sizeof(adj));
		for (int ii=0;ii<V;ii++){
			int i = g[ii].first, j = g[ii].second;
			if (j-1>=0 && a[i][j-1]!='#') adj[ii][imap[make_pair(i,j-1)]] = adj[imap[make_pair(i,j-1)]][ii] = 1;
			if (j+1<x && a[i][j+1]!='#') adj[ii][imap[make_pair(i,j+1)]] = adj[imap[make_pair(i,j+1)]][ii] = 1;
			if (i-1>=0 && a[i-1][j]!='#') adj[ii][imap[make_pair(i-1,j)]] = adj[imap[make_pair(i-1,j)]][ii] = 1;
			if (i+1<y && a[i+1][j]!='#') adj[ii][imap[make_pair(i+1,j)]] = adj[imap[make_pair(i+1,j)]][ii] = 1;
		}
		const int INF = 10000;
		int dist[V][V];
		for (int i=0;i<V;i++) for (int j=0;j<V;j++) dist[i][j] = (adj[i][j]?1:INF);
		for (int i=0;i<V;i++) dist[i][i] = 0;
		// Floyd-Warshall
		for (int k=0;k<V;k++)
			for (int i=0;i<V;i++)
				for (int j=0;j<V;j++)
					if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] < INF && dist[k][j] < INF)
						dist[i][j] = dist[i][k] + dist[k][j];


		// test dist
		for (int i=0;i<V;i++){
			for (int j=0;j<V;j++)
				cout << dist[i][j] << "\t";
			cout << endl;
		}
		// the new graph for MST
		vector<edge> gg[V]; // graph
		for (int i=0;i<V;i++){
			for (int j=i+1;j<V;j++){
				gg[i].push_back(edge(i,j,dist[i][j]));
				gg[j].push_back(edge(j,i,dist[i][j]));
			}
		}
//		// Prim (MST)
		priority_queue<edge> q;
		vector<edge> mst;
		bool marked[V]; memset(marked,false,sizeof(marked));
		long long sum = 0;
		marked[0] = true;
		for (int i=0;i<gg[0].size();i++) q.push(gg[0][i]);
		while (mst.size() < V-1 && !q.empty()){
			edge e = q.top(); q.pop();
			u = e.u;
			v = e.v;
			w = e.w;
			if (marked[u] && marked[v]) continue;
			if (marked[u]){
				for (int i=0;i<gg[v].size();i++) q.push(gg[v][i]);
			}
			if (marked[v]){
				for (int i=0;i<gg[u].size();i++) q.push(gg[u][i]);
			}
			marked[u] = marked[v] = true;
			mst.push_back(e);
			sum += w;
		}
//		if (mst.size() == n-1){
//				cout << sum << endl;
//				pair<int,int> a[n-1];
//				for (int i=0;i<n-1;i++) a[i].first = min(mst[i].u,mst[i].v), a[i].second = max(mst[i].u,mst[i].v);
//				sort(a,a+(n-1));
//				for (int i=0;i<n-1;i++) cout << a[i].first << " " << a[i].second << endl;
//		}
//		else cout << "Impossible" << endl;
		cout << sum << endl;
	}
	return 0;
}
