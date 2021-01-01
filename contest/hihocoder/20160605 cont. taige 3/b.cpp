#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second

using namespace std;

const int N = 110;
int g[N][N];
int n, m, x, y, w;

struct P{
    bool dir[4]; // 对应4个方向的连接块
    P() {memset(dir, 0, sizeof dir);}
}p[N][N];
int t;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

vector<pii > pv;

void bfs(int x, int y) {
    queue<pii > q;
    while(!q.empty()) q.pop();
    q.push({x, y}); // {x, y} == mp(x, y)
    bool vis[N][N];
    memset(vis, 0, sizeof vis);
    vis[x][y] = 1;
    while(!q.empty()) {
        pii z = q.front();
        pv.push_back(z);
        q.pop();
        rep(i, 0, 4) {
            int u = z.fi + dx[i], v = z.se + dy[i];
            if(g[u][v] == w && u >= 0 && v >= 0 && u <= n && v <= m) {
                p[z.fi][z.se].dir[i] = p[u][v].dir[(i+2)%4] = 1;
            }
            if(g[u][v] == w && !vis[u][v] && u >= 0 && v >= 0 && u <= n && v <= m){
                vis[u][v] = 1;
                q.push({u, v});
                p[z.fi][z.se].dir[i] = p[u][v].dir[(i+2)%4] = 1;
            }
        }
    }
    return ;
}

void solve() {
    t = 0; w = g[x][y]; pv.clear();
    rep(i, 0, n) rep(j, 0, m) memset(p[i][j].dir, 0, sizeof p[i][j].dir);
    bfs(x, y);
    int sz = pv.size(), ans = 0;

    rep(i, 0, sz) {
        int x = pv[i].fi, y = pv[i].se;
        rep(j, 0, 4) if(p[x][y].dir[j] == 0) ++ans;
    }
    cout << ans << endl;
}

int main()
{
#ifdef PIT
freopen("b.in", "r", stdin);
#endif // PIT
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> x >> y;
    memset(g, -1, sizeof g);
    rep(i, 0, n) rep(j, 0, m) cin >> g[i][j];
    solve();
    return 0;
}
