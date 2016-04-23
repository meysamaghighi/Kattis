// Meysam Aghighi

#include <cmath>
#include <vector>
#include <iostream>
#include <climits>

#define INF LLONG_MAX

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int N,m,s,t,u,v,c,w;
L temp,path_flow;
VVL cap, flow, cost;
VI found;
VL dist, pi, f;
VPII p;

void Init(){
	cap = VVL(N, VL(N)), flow = VVL(N, VL(N)), cost = VVL(N, VL(N)), found = VI(N), dist = VL(N), pi = VL(N), f = VL(N), p = VPII(N);
}

// pr part
void Relax(int s, int k, L cap, L cost, int dir) {
	L temp = dist[s] + pi[s] - pi[k] + cost;
	if (cap && temp < dist[k]) {
		dist[k] = temp;
		p[k] = make_pair(s, dir);
		f[k] = min(cap, f[s]);
	}
}

// Dahane man service shod sare in code e bi pedar!!! be khodaaa!!!! >:O
L Dijkstra(int s, int t) {
	found = VI(N,false);
	dist = VL(N,INF), dist[s] = 0;
	f = VL(N,0), f[s] = INF;
	while (s != -1) {
		int best = -1;
		found[s] = true;
		for (int k = 0; k < N; k++) {
			if (found[k]) continue;
			Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
			Relax(s, k, flow[k][s], -cost[k][s], -1);
			if (best == -1 || dist[k] < dist[best]) best = k;
		}
		s = best;
	}
	for (int k = 0; k < N; k++) pi[k] = min(pi[k] + dist[k], INF);
	return f[t];
}

void MinCostMaxFlow(int s, int t) {
	L max_flow = 0, min_cost = 0;
	while (path_flow = Dijkstra(s, t)) {
		max_flow += path_flow;
		for (int x = t; x != s; x = p[x].first) {
			if (p[x].second == 1) {
				flow[p[x].first][x] += path_flow;
				min_cost += path_flow * cost[p[x].first][x];
			} else {
				flow[x][p[x].first] -= path_flow;
				min_cost -= path_flow * cost[x][p[x].first];
			}
		}
	}
	cout << max_flow << " " << min_cost << endl;
}

int main(){
	cin >> N >> m >> s >> t;
	Init();
	while(m--){
		cin >> u >> v >> c >> w;
		cap[u][v] = c , cost[u][v] = w;
	}
	MinCostMaxFlow(s,t);
	return 0;
}
