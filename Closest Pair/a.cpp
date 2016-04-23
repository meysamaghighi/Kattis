// Meysam Aghighi
// Divide and Conquer (like quick sort) - to get O(nlogn)
#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
 
struct Point {
    double x, y;
};
 
typedef pair<Point , Point> ppair;
// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
 
// A utility function to find the distance between two points
double dist(Point p1, Point p2){
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
}
 
// For small n's
pair<double , ppair> bruteForce(Point P[], int n){
    double mmin = INT_MAX;
    Point a,b;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < mmin){
                mmin = dist(P[i], P[j]);
                a = P[i];
                b = P[j];
            }
    return make_pair(mmin , make_pair(a,b));
}
 
pair<double , ppair> strip_solve(Point strip[], int size, double d){
    double mmin = d;
    Point a,b;
    // This is the smart part, in runs in O(1) because of the assumption that d is the max
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < mmin; ++j)
            if (dist(strip[i],strip[j]) < mmin){
                mmin = dist(strip[i], strip[j]);
                a = strip[i];
                b = strip[j];
            }
    return make_pair(mmin , make_pair(a,b));
}
 
//  void print(ppair p){
//      cerr << p.first.x << " " << p.first.y << " " << p.second.x << " " << p.second.y << endl;
//  }

// The recursive function, Px and Py are point sorted by x and y, respectively
pair<double, ppair> closest_pair(Point Px[], Point Py[], int n){
    if (n <= 3) return bruteForce(Px, n);
 
    int mid = n/2;
    Point midPoint = Px[mid]; 
 
    // The if-else part takes care of when there are several points with the same x
    Point Pyl[mid];
    Point Pyr[n-mid];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++) {
      if (Py[i].x < midPoint.x && li < mid){
         Pyl[li++] = Py[i];
      }
      else if (ri < n-mid){
         Pyr[ri++] = Py[i];
      }
      else {
          Pyl[li++] = Py[i];
      }         
    }
    
 
    // Divide to half by a vertical line in the middle
    pair<double , ppair> ddl = closest_pair(Px, Pyl, mid);
    pair<double , ppair> ddr = closest_pair(Px + mid, Pyr, n-mid);
 
    // Find the smaller of two distances
    double d;
    ppair pp;
    if (ddl.first < ddr.first){
        d = ddl.first;
        pp = ddl.second;
    }
    else{
        d = ddr.first;
        pp = ddr.second;
    }
    
    // Make strip
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j++] = Py[i];
 
    // Solve strip
    pair<double , ppair> temp = strip_solve(strip, j, d);
    
    // print(pp); print(temp.second);
    return make_pair( min(d, temp.first ) , (d<=temp.first ? pp : temp.second) );
}
 
pair<double , ppair> solve(Point P[], int n){
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++){
        Px[i] = P[i];
        Py[i] = P[i];
    }
 
    // sort(Px,Px+n,compareXX);
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
 
    return closest_pair(Px, Py, n);
}
 
int main(){
    int n;
    while (cin >> n && n){
        Point P[n];
        for (int i=0;i<n;i++){
            cin >> P[i].x >> P[i].y;
        }
        pair<double , ppair> sol = solve(P,n);
        // cout << sol.first << endl;
        printf("%.5f %.5f ",sol.second.first.x,sol.second.first.y);
        printf("%.5f %.5f\n",sol.second.second.x,sol.second.second.y);
        // cout << setprecision(10) << sol.second.first.x << " " << sol.second.first.y << " ";
        // cout << setprecision(10) << sol.second.second.x << " " << sol.second.second.y << endl;
    }
    return 0;
}
