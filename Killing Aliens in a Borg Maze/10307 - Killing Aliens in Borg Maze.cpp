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
        string s;
    cin >> N;
    while (N--){
        cin >> x;
                cin >> y;
        char a[y][x], c;
        vector<pair<int,int> > vertices,g;
        map <pair<int,int> , int > imap;
        int top = 0;
                getline(cin,s);
        for (int i=0;i<y;i++){                    
                    getline(cin,s);
                    for (int j=0;j<s.size();j++){
                        c = s[j];
            if (c == 'A' || c == 'S'){
                g.push_back(make_pair(i,j));
                imap[make_pair(i,j)] = top++;
                vertices.push_back(make_pair(i,j));
            }
            else if (c == ' '){
                g.push_back(make_pair(i,j));
                imap[make_pair(i,j)] = top++;
            }
            a[i][j] = c;
                    }
        }
        int V = g.size();
        int adj[V][V]; memset(adj,0,sizeof(adj));
                vector <int> adjlist[V];
        for (int ii=0;ii<V;ii++){
            int i = g[ii].first, j = g[ii].second;
            if (j-1>=0 && a[i][j-1]!='#') adj[ii][imap[make_pair(i,j-1)]] = adj[imap[make_pair(i,j-1)]][ii] = 1, adjlist[ii].push_back(imap[make_pair(i,j-1)]);
            if (j+1<x && a[i][j+1]!='#') adj[ii][imap[make_pair(i,j+1)]] = adj[imap[make_pair(i,j+1)]][ii] = 1, adjlist[ii].push_back(imap[make_pair(i,j+1)]);
            if (i-1>=0 && a[i-1][j]!='#') adj[ii][imap[make_pair(i-1,j)]] = adj[imap[make_pair(i-1,j)]][ii] = 1, adjlist[ii].push_back(imap[make_pair(i-1,j)]);
            if (i+1<y && a[i+1][j]!='#') adj[ii][imap[make_pair(i+1,j)]] = adj[imap[make_pair(i+1,j)]][ii] = 1, adjlist[ii].push_back(imap[make_pair(i+1,j)]);
        }
        const int INF = 10000;
        int dist[V][V];
                for (int i=0;i<V;i++) for (int j=0;j<V;j++) dist[i][j] = INF;
                // Dijkstra's Algorithm
                priority_queue <int> qq;
                int VV = vertices.size();
                for (int ss=0;ss<VV;ss++){
                    int s = imap[vertices[ss]];
                    qq.push(s);
                    dist[s][s] = 0;
                    while(!qq.empty()){
                        int u = qq.top(); qq.pop();                        
                        for(int i=0;i<adjlist[u].size();i++){
                            int v = adjlist[u][i];
                            if(dist[s][u] + 1 < dist[s][v]){
                                dist[s][v] = dist[s][u] + 1;
                                qq.push(v);
                            }
                        }
                    }
                }
//      // Floyd-Warshall was TLE!!!
        // the new graph for MST                
        vector<edge> gg[VV]; // graph
        for (int i=0;i<VV;i++){
            for (int j=i+1;j<VV;j++){                            
                            int ii = imap[vertices[i]];
                            int jj = imap[vertices[j]];                            
                            gg[i].push_back(edge(i,j,dist[ii][jj]));
                            gg[j].push_back(edge(j,i,dist[ii][jj]));
            }
        }
//      // Prim (MST)
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
        cout << sum << endl;
    }
    return 0;
}