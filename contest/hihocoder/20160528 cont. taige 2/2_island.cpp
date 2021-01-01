#include <bits/stdc++.h>
using namespace std;
#define rep1(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second

const int N = 53;
char c[N];
bool g[N][N];
bool used[N][N];
pair<int, vector<pii > > sharp[N*N];
int t;
int n, m;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void bfs(int x, int y) {
    queue<pii > q;
    q.push(mp(x, y));
    used[x][y] = 1;
    ++t; int z = 0;
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        ++z;
        sharp[t].se.push_back(mp(p.fi, p.se));
        rep(i, 0, 3) {
            int u = p.fi + dx[i], v = p.se + dy[i];
            if(!used[u][v] && g[u][v] && u && u <= n && v && v <= m) {
                used[u][v] = 1;
                q.push(mp(u, v));
                ++z;
            }
        }
    }
    sharp[t].fi = z;
    return ;
}

int trace(int u, int v) {
    int sz = sharp[u].se.size();
//printf("u:%d v:%d sz:%d\n", u, v, sz);
    if(sz == 1) return 1;
    int f = 1;
    rep1(i, 1, sz) {
        int x1 = sharp[u].se[i].fi - sharp[u].se[i-1].fi;
        int y1 = sharp[u].se[i].se - sharp[u].se[i-1].se;
        int x2 = sharp[v].se[i].fi - sharp[v].se[i-1].fi;
        int y2 = sharp[v].se[i].se - sharp[v].se[i-1].se;
//printf("i:%d (x1:%d y1:%d) (x2:%d y2:%d)\n", i, x1, y1, x2, y2);
        if(x1 != x2 || y1 != y2) return 0;
    }
    return 1;
}


void solve() {
    memset(used, false, sizeof used);
    t = -1;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(!used[i][j] && g[i][j]) bfs(i, j);
        }
    }
    ++t; // the number of islands

    sort(sharp, sharp+t);
    sharp[t].fi = -1;

    int tt = 0; // the islands of different area
    rep1(i, 0, t) if(sharp[i].fi != sharp[i+1].fi) ++tt;

    int ttt = 0;
    int l = 0, r = 0;
    bool vis[N*N];
    memset(vis, 0, sizeof vis);
    rep(i, 1, t) {
        if(sharp[i].fi == sharp[i-1].fi) r = i;
        else {
            //printf("l:%d   r:%d\n", l, r);
            if(r > l){
                for(int j = l; j <= r; ++j) {
                    if(vis[j]) continue;
                    for(int k = j+1; k <= r; ++k) {
                        if(vis[k]) continue;
                        if(trace(j, k)) vis[k] = 1;
                    }
                }
       // rep(j, l, r) printf("#%d ", vis[j]); puts("");
            }
            l = r = i;
        }
    }
    //rep1(i, 0, t) printf("%d ", vis[i]); puts("");
    rep1(i, 0, t) if(!vis[i]) ++ttt;

    printf("%d %d %d\n", t, tt, ttt);
}

int main()
{
#ifdef PIT
freopen("2.in", "r", stdin);
#endif // PIT
    scanf("%d %d", &n, &m);
    rep(i, 1, n) {
        scanf("%s", c);
        rep1(j, 0, m) g[i][j+1] = (c[j] == '#');
    }
    solve();
    return 0;
}

