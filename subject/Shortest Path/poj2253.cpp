#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
const int N = 255;
const int inf = 0x3f3f3f3f;

inline int sqr(int x) {return x * x; }

struct P{
    int x, y;
    P(int x = 0, int y = 0) : x(x), y(y) {}
    void in(int i) {scanf("%d %d", &x, &y); }
    int ds(P a) {return sqr(x - a.x)  + sqr(y - a.y);}
}p[N];

int g[N][N];

int n;

double dijkstra() {
    bool used[N];
    int d[N];
    for(int i = 0; i < n; ++i) used[i] = 0, d[i] = inf;

    d[0] = 0;
    while(1) {
        int v = -1;
        for(int u = 0; u < n; ++u) {
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if(v == -1) break;
        used[v] = 1;

        for(int u = 0; u < n; ++u) d[u] = min(d[u], max(d[v], g[v][u]));
    }
    return sqrt(d[1] * 1.0);
}

int main()
{
    #ifdef PIT
    freopen("poj2253.in", "r", stdin);
    #endif // PIT
    int ic = 1;
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; ++i) p[i].in(i);
        for(int i = 0; i < n; ++i) {
            g[i][i] = 0;
            for(int j = i+1; j < n; ++j) g[i][j] = g[j][i] = p[i].ds(p[j]);
        }
        double d = dijkstra();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ic++, d);
    }
    return 0;
}
