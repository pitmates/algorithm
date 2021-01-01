#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define inf 0x3f3f3f3f
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
const int N = 200200;

vector<pii > graph[N];

int dis[N];
bool inq[N];
int node[N];
bool nd[N];

void init() {
    zero(nd);
    rep(i, 0, N) graph[i].clear();
}

void addedge(int u, int v, int w) { graph[u].push_back({v, w}); }

void clr(int src) {
    memset(dis, inf, sizeof dis); dis[src] = 0;
    zero(inq);
}

int spfa(int src, int des) { // bfs
    clr(src);

    deque<int > dq; dq.clear();
    dq.push_back(src);
    while(!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        inq[u] = 0;
        for(int i = 0; i < SZ(graph[u]); ++i) {
            int v = graph[u][i].fi, w = graph[u][i].se, z;
            if(dis[v] > (z = dis[u] + w)) {
                dis[v] = z;
                if(!inq[v]) {
                    inq[v] = 1;
                    if(!dq.empty() && dis[v] > dis[dq.front()]){
                        dq.push_back(v);
                    }
                    else dq.push_front(v);
                }
            }
        }
    }
    return dis[des];
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T, ic = 1;
    for(scanf("%d", &T); T--; ic++){
        int n, m, c;
        scanf("%d %d %d", &n, &m, &c);
        init();
        rep(i, 1, n+1) {
            scanf("%d", node+i);
            nd[node[i]] = 1;
        }
        rep(i, 1, n) if(nd[i] && nd[i+1]) {
            addedge(n + i, n + i+1, c);
            addedge(n + i+1, n + i, c);
        }
        rep(i, 1, n+1) {
            addedge(n + node[i], i, 0);
            if(node[i] > 1) addedge(i, n + node[i] - 1, c);
            if(node[i] < n) addedge(i, n + node[i] + 1, c);
        }
        rep(i, 0, m) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        int ans = spfa(1, n);
        if(ans == inf) ans = -1;
        printf("Case #%d: %d\n", ic, ans);
//        cout << "Case #" << ic << ": " << ans << endl;
    }
    return 0;
}

