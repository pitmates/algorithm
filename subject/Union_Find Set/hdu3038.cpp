#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200200;

int father[N];
int d[N];
int n, m;

void make_set() {
    for(int i = 0; i <= n; ++i) {
        father[i] = i;
        d[i] = 0;
    }
    return ;
}

int find_set(int x) {
    if(x == father[x]) return x;
    int t = find_set(father[x]);
    d[x] = d[x] + d[father[x]];
    father[x] = t;
    return father[x];
}

int ans, w;

void union_set(int u, int v) {
    int x = find_set(u);
    int y = find_set(v);
    if(x != y) {
        father[y] = x;
        d[y] = d[u] - d[v] + w;
    }
    else {
        if(d[v] - d[u] != w) ++ans;
    }
    return ;
}


int main()
{
    while(~scanf("%d %d", &n, &m)) {
        int u, v;
        ans = 0;
        make_set();
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            --u;
            union_set(u, v);
        }
        printf("%d\n", ans);
    }
    return 0;
}
