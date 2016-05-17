// Meysam Aghighi
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct point { 
  double x, y; 
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point(const point &p) : x(p.x), y(p.y) {}
  point operator + (const point &p) const { return point(x+p.x, y+p.y); }
  point operator - (const point &p) const { return point(x-p.x, y-p.y); }
  point operator * (double c) const { return point(x*c, y*c); }
  point operator / (double c) const { return point(x/c, y/c); }
  bool operator < (const point &p) const {
      if (x != p.x) return x < p.x;
      return y < p.y;
  }
};

double dot(point p, point q) { return p.x*q.x + p.y*q.y; } // proportional to cos(x)
double dist(point p, point q) { return sqrt(dot(p-q , p-q)); }
double cross(point p, point q) { return p.x*q.y - p.y*q.x; } // proportional to sin(x) - p to q counterclockwise

point projection(point p, point a, point b){ // projects p on (a,b) - on the closest point on (a,b)
    if (dist(a,b) < EPS) return a;
    double k = dot(p-a,b-a)/dist(a,b); // directed segment from a (projection)
    if (k < 0) return a;
    if (k > dist(a,b)) return b;
    return a + (b-a)*k/dist(a,b);
}


double solve_distance(point a, point b, point c, point d){
    vector<double> D(4,INF);
    point p[4];
    p[0] = projection(a,c,d), p[1] = projection(b,c,d), p[2] = projection(c,a,b), p[3] = projection(d,a,b);
    D[0] = dist(a,p[0]) , D[1] = dist(b,p[1]) , D[2] = dist(c,p[2]) , D[3] = dist(d,p[3]);
    sort(D.begin(),D.end());
    return D[0];
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int ni,no;
        cin >> ni;
        point a[ni];
        for (int i=0;i<ni;i++) cin >> a[i].x >> a[i].y;
        cin >> no;
        point b[no];
        for (int i=0;i<no;i++) cin >> b[i].x >> b[i].y;
        double best = solve_distance(a[0],a[ni-1],b[0],b[no-1]);
        for (int i=1;i<ni;i++){
            for (int j=1;j<no;j++){
                best = min(best,solve_distance(a[i-1],a[i],b[j-1],b[j]));
            }
        }
        best /= 2;
        printf("%.10lf\n",best);
        // cout << best/2 << endl;
    }
    return 0;
}