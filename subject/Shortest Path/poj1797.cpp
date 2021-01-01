#include <iostream>
#include <cstdio>

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1023;

int g[N][N];

int n, m;

int dijkstra() {
    int d[N];
    bool used[N];

    for(int i = 1; i <= n; ++i) {
        used[i] = false;
        d[i] = g[1][i];
    }

    d[1] = inf;
    while(true) {
        int v = -1, u;
        for(u = 1; u <= n; ++u) {
            if(!used[u] && (v == -1 || d[v] < d[u])) v = u;
        }

        if(v == -1) break;
        used[v] = true;

        for(u = 1; u <= n; ++u) {
            if(!used[u] && d[u] < min(d[v], g[v][u])) d[u] = min(d[v], g[u][v]);
        }
//printf("v == %d   ", v); for(int i = 1; i <= n; ++i) printf("%d ", d[i]);puts("");

    }
    return d[n];

}

int main()
{
#ifdef PIT
freopen("poj1797.in", "r", stdin);
#endif // PITT
    int T, ic = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j < i; ++j) g[i][j] = g[j][i] = 0;
            g[i][i] = inf;
        }

        for(int i = 0, u, v, w; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] = g[v][u] = w;
        }
        printf("Scenario #%d:\n%d\n\n", ic++, dijkstra());
    }
    return 0;
}
