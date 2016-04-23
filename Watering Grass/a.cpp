// Mega Noobs

#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct interval{
    double a;
    double b;
    int index;

    bool operator < (interval x) const {
        return a < x.a;
    }
};

double A,B,maxx;    
int n, it, best;
vector<int> cover;
bool possible;

int main(){
	int n,l;
	double r,w,x;
	while (cin >> n >> l >> w){
		interval intervals[n];
		for (int i=0;i<n;i++){
			cin >> x >> r; // position radius => build intervals
			if (r >= w/2){
				double p = sqrt(r*r -w*w/4);
				intervals[i].a = x - p;
				intervals[i].b = x + p;
				intervals[i].index = i;
			}
			else {
				intervals[i].a = -1;
				intervals[i].b = -1;
				intervals[i].index = i;
			}
		}
		A = 0;
		B = l;

        sort(intervals,intervals+n); // increasing
        it = 0;
        cover.clear();
        possible = true;
        // it++ until sth reasonable
        while (intervals[it].b < A){
            it++;
            if (it == n){
                possible = false;
                break;
            }
        }
        if (A == B && possible){
            if (intervals[it].a <= A && intervals[it].b >= A)
                cover.push_back(intervals[it].index);
            else possible = false;
        }
        while (A < B && possible){
            if (it == n){
                possible = false;
                break;
            }
            maxx = -1;
            best = -1;
            while (intervals[it].a <= A){
                if (intervals[it].b - A > maxx){
                    maxx = intervals[it].b - A;
                    best = it;
                }
                it++;
                if (it == n) break;
            }
            if (best == -1){
                possible = false;
                break;
            }
            cover.push_back(intervals[best].index);
            A = intervals[best].b;
        }
        if (!possible)
            printf("-1\n");
        else{
            printf("%lu\n",cover.size());
//            for (int i=0;i<cover.size();i++)
//                    printf("%s%d",(i?" ":""),cover[i]);
//            printf("\n");
        }
	}

    return 0;
}