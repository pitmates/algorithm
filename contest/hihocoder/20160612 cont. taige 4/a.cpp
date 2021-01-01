#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 511;
int n, m;
bool vis[N], flag;

set<int > p[N];

void dfs(int pre, int now) {
    if(vis[now]) {
        flag = 1;
        return;
    }
    vis[now] = 1;
    for(set<int >::iterator it = p[now].begin(); it != p[now].end(); ++it) {
        if(*(it) == pre) continue;
        dfs(now, *(it));
    }
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    int T;
    for(scanf("%d", &T); T; --T) {
        scanf("%d %d", &n, &m);
        int u, v;
        rep(i, 1, n) p[i].clear();
        while(m--) {
            scanf("%d %d", &u, &v);
            p[u].insert(v); p[v].insert(u);
        }
        memset(vis, 0, sizeof vis);
        flag = 0; dfs(0, 1);
        u = 0; rep(i, 1, n) if(vis[i]) ++u;
        if(u < n) flag = 1;
        puts((flag) ? "NO" : "YES");
    }
    return 0;
}
