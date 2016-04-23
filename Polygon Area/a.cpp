// Meysam Aghighi
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long T;
// typedef double T;

double INF = 1e100;
double EPS = 1e-12;

struct point { 
  T x, y; 
  point() {}
  point(T x, T y) : x(x), y(y) {}
  point(const point &p) : x(p.x), y(p.y) {}
  point operator + (const point &p) const { return point(x+p.x, y+p.y); }
  point operator - (const point &p) const { return point(x-p.x, y-p.y); }
  point operator * (T c) const { return point(x*c, y*c); }
  point operator / (T c) const { return point(x/c, y/c); }
  bool operator < (const point &p) const { return x < p.x || (x == p.x && y < p.y); }
};

T dot(point p, point q) { return p.x*q.x + p.y*q.y; } // proportional to cos(x)
double dist(point p, point q) { return sqrt(dot(p-q , p-q)); }
T cross(point p, point q) { return p.x*q.y - p.y*q.x; } // proportional to sin(x) - p to q counterclockwise

bool segments_parallel(point a, point b, point c, point d){ // if (a,b) || (c,d)
    return abs(cross(a-b,c-d)) < EPS; // sin(x) = 0
}

bool point_on_segment(point p, point a, point b){ // p belongs to (a,b) or not - gives false for a and b
    if (segments_parallel(p,a,p,b) && dot(p-a,p-b) < 0) return true; // to check
    return false;
}

bool segments_intersect(point a, point b, point c, point d){    
    if (dist(a,c) < EPS || dist(a,d) < EPS || dist(b,c) < EPS || dist(b,d) < EPS) return true;
    if (dist(a,b) < EPS && dist(c,d) < EPS) return false;
    if (dist(a,b) < EPS) return point_on_segment(a,c,d);
    if (dist(c,d) < EPS) return point_on_segment(c,a,b); 
    if (segments_parallel(a,b,c,d) && segments_parallel(a,c,b,d) && segments_parallel(a,d,b,c)){
        if (point_on_segment(a,c,d) || point_on_segment(b,c,d) || point_on_segment(c,a,b) || point_on_segment(d,a,b)) return true;
        return false;
    }
    if (cross(a-b,a-c) * cross(a-b,a-d) > 0) return false; // c and d are one side of (a,b)
    if (cross(c-d,c-a) * cross(c-d,c-b) > 0) return false; // a and b are one side of (c,d)
    return true;
}

point lines_intersection(point a, point b, point c, point d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

void print(point a, point b, point c, point d){
    point x[4];
    x[0] = a , x[1] = b, x[2] = c, x[3] = d;
    sort(x,x+4);
    if (dist(x[1],x[2]) < EPS) printf("%.2f %.2f",x[1].x,x[1].y);
    else for (int i=1;i<3;i++) printf("%.2f %.2f ",x[i].x,x[i].y);
    printf("\n");
}

void solve_intersection(point a, point b, point c, point d){
    if (!segments_intersect(a,b,c,d)) cout << "none" << endl; // no intersection
    else if (segments_parallel(a,b,c,d)){ // intersection, includes a=b cases...
        if (dist(a,b) < EPS) printf("%.2f %.2f\n",a.x,a.y);
        else if (dist(c,d) < EPS) printf("%.2f %.2f\n",c.x,c.y);
        else print(a,b,c,d); // prints the two middle points (could be equal)
    }
    else {
        point ans = lines_intersection(a,b,c,d); // normal intersection, when there is one
        printf("%.2f %.2f\n",ans.x,ans.y);            
    }   
}

vector<point> convex_hull(vector<point> p){
    int n = p.size() , k = 0;
    vector<point> h(2*n);
    sort(p.begin(),p.end());
    // Lower half
    for (int i=0;i<n;i++){
        while (k >= 2 && cross(h[k-1]-h[k-2] , p[i]-h[k-2]) <= 0) k--;
        h[k++] = p[i];
    }
    int temp = k+1;
    // Upper half
    for (int i=n-2;i>=0;i--){
        while (k >= temp && cross(h[k-1]-h[k-2] , p[i]-h[k-2]) <= 0) k--;
        h[k++] = p[i];
    }
    h.resize(k-1);
    return h;
}

double signed_area(const vector<point> &p){ // returns the signed area
    T area = 0;
    for (int i=0;i<p.size();i++){
        int j = (i+1) % p.size();
        area += cross(p[i],p[j]);
    }
    return area/2.0;
}

int main(){
    int n;    
    while (cin >> n && n){
        vector<point> a(n);
        for (int i=0;i<n;i++) cin >> a[i].x >> a[i].y;
        double area = signed_area(a);
        if (area >= 0) cout << "CCW ";
        else cout << "CW ";
        printf("%.1f\n",abs(area)); 
    }
    return 0;
}
