#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 12;
int n, m;
char s[N];
bool v[N][N], g[N][N];
int t;

struct P{
    int x, y;
    int rs;
    P(int x = 0, int y = 0, int r = 0) : x(x), y(y), rs(r) {}
}p[N*N];


inline void eq() {
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) g[i][j] = v[i][j];
    for(int i = 0; i < t; ++i) p[i].rs = 0;
    return ;
}

queue<P >que;

int bfs(int b, int c) {
    eq();
    int tt = 2, r = 0;
    g[p[b].x][p[b].y] = 0; g[p[c].x][p[c].y] = 0;

    while(!que.empty()) que.pop();
    que.push(p[b]), que.push(p[c]);

    while(!que.empty()) {
        P tp = que.front();
        que.pop();
//printf("%d %d   %d %d -- ", tp.x, tp.y, que.front().x, que.front().y);
        if(g[tp.x-1][tp.y] == 1) {
            P pp = P(tp.x-1, tp.y, tp.rs+1);
            que.push(pp);
            g[tp.x-1][tp.y] = 0;
            ++tt;
            r = max(pp.rs, r);
        }
        if(g[tp.x+1][tp.y] == 1) {
            P pp = P(tp.x+1, tp.y, tp.rs+1);
            que.push(pp);
            g[tp.x+1][tp.y] = 0;
            ++tt;
            r = max(pp.rs, r);
        }
        if(g[tp.x][tp.y-1] == 1) {
            P pp = P(tp.x, tp.y-1, tp.rs+1);
            que.push(pp);
            g[tp.x][tp.y-1] = 0;
            ++tt;
            r = max(pp.rs, r);
        }
        if(g[tp.x][tp.y+1] == 1) {
            P pp = P(tp.x, tp.y+1, tp.rs+1);
            que.push(pp);
            g[tp.x][tp.y+1] = 0;
            ++tt;
            r = max(pp.rs, r);
        }
    }
    if(tt < t) return 1000;
    else return r;
}

int main()
{
    #ifdef PIT
    freopen("fzu2150.in", "r", stdin);
    #endif // PIT
    int T, ic = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        memset(v, 0, sizeof v);
        t = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            for(int j = 0; j < m; ++j) {
                if(s[j] == '.') v[i][j+1] = 0;
                else {
                    v[i][j+1] = 1;
                    p[t++] = P(i, j+1, 0);
                }
            }
        }

        printf("Case %d: ", ic++);
        if(t < 2) printf("0\n");
        else {
            int ans = 0, minv = 1000;
            for(int i = 0; i < t; ++i)
            for(int j = i+1; j < t; ++j){
                ans = bfs(i, j);
                minv = min(minv, ans);
            }
            if(minv == 1000) minv = -1;
            printf("%d\n", minv);
        }
    }
    return 0;
}
