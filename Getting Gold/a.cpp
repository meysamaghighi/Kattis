// Meysam Aghighi

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> point;
#define x first
#define y second

int main(){
    int W,H;
    cin >> W >> H;
    char a[H][W]; bool marked[H][W]; memset(marked,false,sizeof(marked));
    point start;
    for (int i=0;i<H;i++) for (int j=0;j<W;j++){
        cin >> a[i][j];
        if (a[i][j] == 'P') start = make_pair(i,j);
    }
    queue<point> q;
    q.push(start);
    int answer = 0;
    while (!q.empty()){
        point p = q.front(); q.pop();
        char v = a[p.x][p.y];
        if (marked[p.x][p.y]) continue;
        marked[p.x][p.y] = true;
        bool safe = true;
        if (v == '#') continue;
        if (v == 'G') answer++;
        // if safe
        if (p.y - 1 >= 0 && a[p.x][p.y-1]=='T') safe = false;
        if (p.y + 1 <= W-1 && a[p.x][p.y+1]=='T') safe = false;
        if (p.x - 1 >= 0 && a[p.x-1][p.y]=='T') safe = false;
        if (p.x + 1 <= H-1 && a[p.x+1][p.y]=='T') safe = false;
        
        if (safe){
            if (p.y - 1 >= 0 && (a[p.x][p.y-1]=='.' || a[p.x][p.y-1]=='G')) q.push(make_pair(p.x,p.y-1));
            if (p.y + 1 <= W-1 && (a[p.x][p.y+1]=='.' || a[p.x][p.y+1]=='G')) q.push(make_pair(p.x,p.y+1));
            if (p.x - 1 >= 0 && (a[p.x-1][p.y]=='.' || a[p.x-1][p.y]=='G')) q.push(make_pair(p.x-1,p.y));
            if (p.x + 1 <= H-1 && (a[p.x+1][p.y]=='.' || a[p.x+1][p.y]=='G')) q.push(make_pair(p.x+1,p.y));
        }                
    }
    cout << answer << endl;
    
    return 0;
}