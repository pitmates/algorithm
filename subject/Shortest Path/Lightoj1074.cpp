#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
const int N = 222;
int busy[N];
int n;
int dis[N];
vector<pii > G[N];

inline ll cube(int x, int y) {
    return 1LL* (y - x) * (y - x) * (y - x);
}

void addedge(int u, int v, int w) {
    G[u].PB({v, w}); return ;
}

bool circle[N];
void dfs(int v) {
    circle[v] = 1;
    rep(i, 0, SZ(G[v])) {
        int u = G[v][i].fi;
        if(!circle[u]) dfs(u);
    }
}
bool inq[N];
int cnt_inq[N];
void spfa(int s) {
    zero(inq); zero(cnt_inq); zero(circle);
    rep(i, 1, n+1) dis[i] = INF; dis[s] = 0;

    queue<int > Q;
    while(!Q.empty()) Q.pop();
    Q.push(s); ++cnt_inq[s];
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        rep(i, 0, SZ(G[u])) {
            int v = G[u][i].fi, w = G[u][i].se;
            if(circle[v]) continue;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!inq[v]){
                    inq[v] = 1;
                    Q.push(v);
                    if(++cnt_inq[v] > n) dfs(v); //return 0;
                }
            }
        }
    }
    // return 1;
}

void spfa_SLF(int s) {
    zero(inq); zero(cnt_inq); zero(circle);
    rep(i, 1, n+1) dis[i] = INF; dis[s] = 0;

    deque<int > dq;
    while(!dq.empty()) dq.pop_back();
    dq.push_back(s); ++cnt_inq[s];
    while(!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        inq[u] = 0;
        rep(i, 0, SZ(G[u])) {
            int v = G[u][i].fi, w = G[u][i].se;
            if(circle[v]) continue;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!inq[v]) {
                    inq[v] = 1;
                    if(!dq.empty() && dis[v] > dis[dq.front()]) dq.push_back(v);
                    else dq.push_front(v);
                    if(++cnt_inq[v] > n) dfs(v); //return 0;
                }
            }
        }
    }
    // return 1;
}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    int T, ic = 1;
    for(scanf("%d", &T); T--; ic++) {
        scanf("%d", &n);
        rep(i, 1, n+1) scanf("%d", busy+i);
        rep(i, 1, n+1) G[i].clear();
        int m, q;
        scanf("%d", &m);
        while(m--) {
            int a, b;
            scanf("%d %d", &a, &b);
            addedge(a, b, cube(busy[a], busy[b]));
        }
        scanf("%d", &q);
        printf("Case %d:\n", ic);
        //spfa(1);
        spfa_SLF(1);
        while(q--) {
            int a;
            scanf("%d", &a);
            if(dis[a] < 3 || dis[a] == INF || circle[a]) puts("?");
            else printf("%d\n", dis[a]);
//            if(x < 3 || x >= inf) puts("?");
//            else printf("%lld\n", x);
        }
    }
    return 0;
}
