#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int N = 1010;
const int inf = 0x3f3f3f3f;

int n, m;

struct edge{
    int to;
    int cost;
    edge(){}
    edge(int t, int c) : to(t), cost(c) {}
};

typedef pair<int, int > P;
vector<vector<edge > >G(N);
vector<vector<edge > >RG(N);

int d[N];
int rd[N];

//int v, e; // ¶¥µã£¬ ±ß

void dijkstra(int s) {
    priority_queue<P, vector<P >, greater<P > > que;
    for(int i = 0; i < N; ++i) d[i] = inf;
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    int x;
    while(~scanf("%d %d %d", &n, &m, &x)) {
        --x;
        for(int i = 0, a, b, t; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &t);
            --a, --b;
            G[a].push_back(edge(b, t));
            RG[b].push_back(edge(a, t));
        }
        dijkstra(x);
        G = RG;
        for(int i = 0; i < n; ++i) rd[i] = d[i];
//        memcpy(rd, d, sizeof d);
        dijkstra(x);
        for(int i = 0; i < n; ++i) d[i] += rd[i];
        int maxv = 0;
        for(int i = 0; i < n; ++i) maxv = max(maxv, d[i]);
//        maxv = *max_element(d, d+n);
        printf("%d\n", maxv);

    }
    return 0;
}
