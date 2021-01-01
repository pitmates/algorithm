#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define inf 0x7f3f3f3f
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
typedef unsigned int ll;
const int N = 5002;

struct Graph{
    int v, w, next;
}graph[N];

int head[N];
int pre[N][N];
ll dis[N][N];
bool inq[N][N];
deque<int > q1, q2;

void update(int u1, int u2, int v1, int v2, ll W) {
    if(dis[v1][v2] == inf || dis[v1][v2] > W) {
        dis[v1][v2] = W;
        pre[v1][v2] = u1;
        if(!inq[v1][v2]) {
            inq[v1][v2] = true;
            q1.push_back(v1);
            q2.push_back(v2);
        }
    }
    return ;
}

deque<int > spfa(int src, int des, ll T) {
    q1.clear(); q2.clear();
    memset(dis, inf, sizeof dis);
    zero(inq);

    update(0, 0, src, 1, 0);
    while(!q1.empty()) {
        int u1, u2, v1, v2, w;
        u1 = q1.front(); q1.pop_front();
        u2 = q2.front(); q2.pop_front();
        inq[u1][u2] = false;

        for(int i = head[u1]; i != -1; i = graph[i].next) {
            v1 = graph[i].v; v2 = u2 + 1; w = graph[i].w;
            update(u1, u2, v1, v2, dis[u1][u2] + w);
        }
    }

    for(int i = N-1; i >= 0; --i) if(dis[des][i] <= T) {
        deque<int > s;
        for(int u1 = des, u2 = i; u2; u1 = pre[u1][u2], --u2)
            s.push_front(u1);
        return s;
    }
    return deque<int >();
}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; ll t;
    cin >> n >> m >> t;
    int idx = 0, u, v, w;
    memset(head, -1, sizeof head);
    rep(i, 0, m) {
        cin >> u >> v >> w;
        graph[idx] = {v, w, head[u]};
        head[u] = idx++;
    }

    deque<int > ans = spfa(1, n, t);

    cout << SZ(ans) << endl;
    rep(i, 0, SZ(ans)) {
        if(i) cout << " " << ans[i];
        else cout << ans[i];
    }
    return 0;
}
