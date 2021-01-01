#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int)j; i <= (int)k; ++i)
using namespace std;
const int N = 6e5+7;

struct P{
    int x, y, z;
    void in() {scanf("%d %d %d", &x, &y, &z); }
}a[N];

int t, idx, inx, n, m, r, l, st, ed;
int low[N], dfn[N], id[N];
int s[N], q[N];
bool g[N];
int nt[N], lt[N], to[N], ve[N];

inline void add_edge(int x, int y, int z) {
    nt[++t] = lt[x]; lt[x] = t; to[t] = y; ve[t] = z;
}

void tarjan(int rt, int ft) {
    low[rt] = dfn[rt] = ++inx;
    q[++r] = rt; g[rt] = 1;
    for(int i = lt[rt], j; i; i = nt[i]) {
        j = to[i];
        if(j == ft) continue;
        if(!dfn[j]) {
            tarjan(j, rt);
            low[rt] = min(low[rt], low[j]);
        }
        else if(g[j]){
            low[rt] = min(low[rt], dfn[j]);
        }
    }
    if(dfn[rt] == low[rt]) {
        ++idx;
        do {
            g[q[r]] = 0;
            id[q[r]] = idx;
        }while(q[r--] != rt);
    }
    return ;
}

void bfs(int st) {
    l = 0; r = 1; q[1] = st; g[st] = 1;
    while(l < r) {
        int x = q[++l];
        for(int i = lt[x], j; i; i = nt[i]) {
            j = to[i];
            if(g[j]) continue;
            g[j] = 1; q[++r] = j;
            s[j] |= s[x] | ve[i];
        }
    }

    puts(s[id[ed]] ? "YES" : "NO");
    return ;
}

int main()
{
    scanf("%d %d", &n, &m);
    t = inx = idx = l = r = 0;
    rep(i, 1, m) {
        a[i].in();
        add_edge(a[i].x, a[i].y, a[i].z);
        add_edge(a[i].y, a[i].x, a[i].x);
    }
    scanf("%d %d", &st, &ed);
    tarjan(1, 0);
    t = 0; memset(lt, 0, sizeof lt);
    rep(i, 1, m) {
        if(id[a[i].x] == id[a[i].y]) s[id[a[i].x]] = max(s[id[a[i].x]], a[i].z);
        else add_edge(id[a[i].x], id[a[i].y], a[i].z), add_edge(id[a[i].y], id[a[i].x], a[i].z);
    }
    if(id[st] == id[ed]) puts(s[id[st]] ? "YES" : "NO");
    else bfs(id[st]);
    return 0;
}
