#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
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
const int N = 330;

int cost[N][N];
int n;
int d[N];
int inq[N];

void spfa(int src, int des) {
    zero(inq); d[src] = inf;

    queue<int > Q;
    while(!Q.empty()) Q.pop();
    rep(i, 1, n) {
        if(i == src) continue;
        d[i] = cost[src][i];
        inq[i] = 1;
        Q.push(i);
    }

    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        rep(v, 1, n) if(d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                if(!inq[v]) {
                    inq[v] = 1;
                    Q.push(v);
                }
            }
    }
    return ;
}

void dijkstra(int src, int des) {
    d[src] = inf;
    priority_queue<pii > pq;
    while(!pq.empty()) pq.pop();
    rep(i, 1, n) {
        if(i == src) continue;
        d[i] = cost[src][i];
        pq.push({-d[i], i});
    }

    while(!pq.empty()) {
        pii tp = pq.top(); pq.pop();
        int u = tp.se, z = tp.fi;
        if(d[u] < -z) continue;
        rep(v, 1, n) if(d[v] > (z = d[u] + cost[u][v])){
            d[v] = z;
            pq.push({-d[v], v});
        }

    }
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    //ios_base::sync_with_stdio(false); cin.tie(0);

    while(~scanf("%d", &n)){
        rep(i, 1, n) rep(j, 1, n) scanf("%d", cost[i] + j);
        dijkstra(1, n);
        int ans = d[n], loop1 = d[1], loop2;
        dijkstra(n, n);
        loop2 = d[n];
        ans = min(ans, loop1 + loop2);
        printf("%d\n", ans);
    }
    return 0;
}
