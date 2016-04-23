// Meysam Aghighi
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define mp make_pair

const pair<int,int> dir[8] = {mp(1,2),mp(1,-2),mp(-1,2),mp(-1,-2),mp(2,1),mp(2,-1),mp(-2,1),mp(-2,-1)};

bool inbound(int x ,int y){
    return (x>=0 && x<8) && (y>=0 && y<8);
}

int main(){
    int n,x,y,c,maxx;
    int dist[8][8];
    string s;
    cin >> n;
    while (n--){
        memset(dist,-1,sizeof(dist));
        cin >> s;
        x = s[0]-'a' , y = s[1]-'1';
        c = 20;
        dist[x][y] = 0;
        maxx = 0;
        while (c--){
            for (int i=0;i<8;i++){
                for (int j=0;j<8;j++){
                    if (dist[i][j] != -1){ // if we have already reached this step
                        for (int k=0;k<8;k++){
                            int xx = i + dir[k].first , yy = j + dir[k].second;
                            if (inbound(xx,yy)){
                                if (dist[xx][yy] > dist[i][j] + 1 || dist[xx][yy] == -1){
                                    dist[xx][yy] = dist[i][j] + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=0;i<8;i++) for (int j=0;j<8;j++) maxx = max(maxx,dist[i][j]);
//        for (int j=7;j>=0;j--){
//            for (int i=0;i<8;i++)
//                cerr << dist[i][j] << " ";
//            cerr << endl;
//        }
        cout << maxx;
        for (int j=7;j>=0;j--) for (int i=0;i<8;i++) if (dist[i][j] == maxx) cout << " " << (char)(i+'a') << (char)(j+'1');
        cout << endl;
    }
    return 0;
}
