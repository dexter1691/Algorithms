nclude <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const double pi = acos(-1.0);
const double eps = 1e-6;

struct pt {
    double x, y;
    pt() {}
    pt(double _x, double _y):x(_x), y(_y) {}
    pt rot(double k) const {return pt(x * cos(k) - y * sin(k), x * sin(k) + y * cos(k));}
    void rd() {scanf("%lf%lf", &x, &y);}
} pts[100010];

int n;

bool cmpx(const pt &a, const pt &b) {
    return a.x < b.x;
}

double lmaxy[100010], lminy[100010];
double rmaxy[100010], rminy[100010];
double px[100010];

bool check(double R) {
    R /= sqrt(2.0);
    int ps = 0;
    REP(i, n) {
        double miny = 1e50, maxy = -1e50;
        if (i > 0) {
            miny = min(miny, lminy[i - 1]);
            maxy = max(maxy, lmaxy[i - 1]);
        }
        while (ps < n && px[ps] - px[i] < R + eps) ++ps;
        //cout << R << ":" << i << endl;
        if (ps < n) {
            miny = min(miny, rminy[ps]);
            maxy = max(maxy, rmaxy[ps]);
        }
        if (maxy - miny < R + eps) return true;
    }
    return false;
}

int main() {
    while (~scanf("%d", &n)) {
        
        REP(i, n) pts[i].rd();
        REP(i, n) pts[i] = pts[i].rot(pi/4);
        
        sort(pts, pts + n, cmpx);
        
        lmaxy[0] = lminy[0] = pts[0].y;
        
        for (int i = 1; i < n; ++i) {
            lmaxy[i] = max(lmaxy[i - 1], pts[i].y);
            lminy[i] = min(lminy[i - 1], pts[i].y);
        }
        
        rmaxy[n - 1] = rminy[n - 1] = pts[n - 1].y;
        
        for (int i = n - 2; i >= 0; --i) {
            rmaxy[i] = max(rmaxy[i + 1], pts[i].y);
            rminy[i] = min(rminy[i + 1], pts[i].y);
        }
        
        REP(i, n) px[i] = pts[i].x;

        double st = 0, ed = 4e9;

        while (st + eps < ed) {
            double mid = (st + ed) * 0.5;
            if (check(mid + mid)) {
                ed = mid;
            } else {
                st = mid;
            }
        }
        printf("%.15f\n", st);
    }
    return 0;
}
