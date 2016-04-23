// Meysam Aghighi

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

struct edge{
    int to, id;
    edge(int _to, int _id){
        to = _to;
        id = _id;
    }
};

int main(){
    int n,m,u,v;
    while (cin >> n >> m && n){
    	vector<edge> g[n];
    	vector<int> in_deg(n,0), out_deg(n,0);
        for (int i=0;i<m;i++){
            cin >> u >> v;
            g[u].push_back(edge(v,i));
            out_deg[u]++;
            in_deg[v]++;
        }
        // find start node
        int start = u, total = 0;
        for (int i=0;i<n;i++){
        	if (out_deg[i] != in_deg[i]) total++;
        	if (out_deg[i] - in_deg[i] == 1){
        		start = i;
        	}
        }
        stack<int> s;
        vector<int> path;
        bool marked[m]; memset(marked,false,sizeof(marked));
        int cur = start;
        while(!s.empty() || out_deg[cur]){
        	if (!out_deg[cur]){
        		path.push_back(cur);
        		cur = s.top(); s.pop();
        		continue;
        	}
        	else{
        		for (int i=0;i<g[cur].size();i++){
        			edge e = g[cur][i];
        			int to = e.to, id = e.id;
        			if (!marked[id]){
        				out_deg[cur]--;
        				marked[id] = true;
        				s.push(cur);
        				cur = to;
        				break;
        			}
        		}
        	}
        }
        path.push_back(cur);
        if (path.size() == m+1 && (total==0 || total==2)){ // The check on total got it accepted!!!
            for (int i=m;i>=0;i--) cout << (i!=m?" ":"") << path[i];
            cout << endl;
        }
        else cout << "Impossible" << endl;
    }
    return 0;
}
