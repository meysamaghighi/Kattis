// Meysam Aghighi

#include <cstdio>
using namespace std;

const int INF = 1000000;
int dist[200][200];
int n,m,q,u,v,w;

int main(){
	while (scanf("%d%d%d",&n,&m,&q)==3 && n){
		int dist[n][n];
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) dist[i][j] = (i==j?0:INF);
		for (int i=0;i<m;i++) scanf("%d%d%d",&u,&v,&w), dist[u][v] = (w < dist[u][v]?w:dist[u][v]);
		// floyd - warshal
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] < INF && dist[k][j] < INF)
						dist[i][j] = dist[i][k] + dist[k][j];
		// detect negative cycles
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				for (int k=0;dist[i][j]!=-INF && k<n;k++)
					if (dist[k][k]<0 && dist[i][k]!=INF && dist[k][j]!=INF)
						dist[i][j] = -INF;
		// queries
		for (int i=0;i<q;i++){
			scanf("%d%d",&u,&v);
			if (dist[u][v] == INF) printf("Impossible\n");
			else if (dist[u][v] == -INF) printf("-Infinity\n");
			else printf("%d\n",dist[u][v]);
		}
		printf("\n");
	}
    return 0;
}
