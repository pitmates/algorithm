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

struct Graph {
    int v, w, next;
}E[N<<3];

int d[N];
int node[N];
int nd[N];
int head[N];
int idx;

void init() {
    zero(nd); idx = 0;
    memset(head, -1, sizeof head);
}

void addedge(int u, int v, int w) {
    E[idx] = {v, w, head[u]};
    head[u] = idx++;
}

int dijkstra(int src, int des) { // dfs
    memset(d, inf, sizeof d); d[src] = 0;

    priority_queue<pii > pq;
    while(!pq.empty()) pq.pop();
    pq.push({-d[src], src});
    while(!pq.empty()) {
        pii t = pq.top(); pq.pop();
        int u = t.se, x = t.fi;
        if(d[u] < -x) continue;
        for(int i = head[u]; i != -1; i = E[i].next) {
            int v = E[i].v, w = E[i].w, z;
            if(d[v] > (z = d[u] + w)) {
                d[v] = z;
                pq.push({-d[v], v});
            }
        }
    }
    return d[des] == inf ? -1 : d[des];
}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
   // ios_base::sync_with_stdio(false); cin.tie(0);

    int T, ic = 1;
    for(scanf("%d", &T); T--; ic++) {
        int n, m, c;
        scanf("%d %d %d", &n, &m, &c);
        init();
        rep(i, 1, n+1) scanf("%d", node+i), nd[node[i]] = 1;

        rep(i, 1, n) if(nd[i] && nd[i+1]) {
            addedge(n+i, n+i+1, c);
            addedge(n+i+1, n+i, c);
        }
        rep(i, 1, n+1) {
            addedge(n+node[i], i, 0);
            if(node[i] > 1) addedge(i, n+node[i]-1, c);
            if(node[i] < n) addedge(i, n+node[i]+1, c);
        }
        rep(i, 0, m) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        printf("Case #%d: %d\n", ic, dijkstra(1, n));
//        cout << "Case #" << ic << ": " << dijkstra(1, n) << endl;
    }
    return 0;
}
