// Meysam Aghighi

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
    double x;
    double y;
};

bool wayToSort(point a, point b){
    return (a.y<b.y);
}

double dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main(){
    int N;
    double L,W;
    cin >> N;
    cin >> L;
    cin >> W;
    int n = N/2;
    point tree[N];
    for (int i=0;i<N;i++){
        cin >> tree[i].y;
        tree[i].x = 0;
    }
    sort(tree,tree+N,wayToSort);
    
//    for (int i=0;i<N;i++)
//        cout << tree[i].x << " " << tree[i].y << endl;
//    
    point Left[n];
    point Right[n];
    for (int i=0;i<n;i++){
        Left[i].x = 0;
        Left[i].y = i*L/(n-1);
        Right[i].x = W;
        Right[i].y = Left[i].y;
    }
//    for (int i=0;i<n;i++)
//        cout << Left[i].x << "," << Left[i].y << " " << Right[i].x << "," << Right[i].y << endl;
    double answer[n+1][n+1];
//    cout << "n=" << n << endl;
    answer[0][0] = 0;
    for (int i=1;i<n+1;i++)
        answer[i][0] = answer[i-1][0] + dist(tree[i-1],Left[i-1]);
    for (int j=1;j<n+1;j++)
        answer[0][j] = answer[0][j-1] + dist(tree[j-1],Right[j-1]);
    for (int i=1;i<n+1;i++)
        for (int j=1;j<n+1;j++)
            answer[i][j] = min(answer[i-1][j]+dist(tree[i+j-1],Left[i-1]),answer[i][j-1]+dist(tree[i+j-1],Right[j-1]));

    cout.precision(11);
    cout << answer[n][n] << endl;
    return 0;
}