    // Meysam Aghighi
    #include <bits/stdc++.h>
    using namespace std;
    
    // typedef long long T;
    typedef double T;

    double INF = 1e100;
    double EPS = 1e-12;
    double pi = 3.141592653;

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
        int t; cin >> t;    
        while (t--){
            int n; cin >> n;
            vector<point> a(4*n);
            double x,y,w,h,v,s=0;
            for (int i=0;i<4*n;i+=4){
                cin >> x >> y >> w >> h >> v;
                s += w*h;
                v = v/180*pi;
                point h2(sin(v),cos(v)), w2(-cos(v),sin(v)), p(x,y);
                h2 = h2*(h/2); w2 = w2*(w/2);
                a[i] = p + h2 + w2;
                a[i+1] = p + h2 - w2;
                a[i+2] = p - h2 + w2;
                a[i+3] = p - h2 - w2;
            }
            double S = abs(signed_area(convex_hull(a)));
            double ans = s/S*100;
            printf("%.1lf %%\n",ans);
        }
        return 0;
    }