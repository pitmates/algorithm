#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

void rd(int &x) {
    x = 0; int f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    return ;
}

const int N = 110;


int f[N];
int u[N], v[N];
int n;

void makeset() {
    for(int i = 1; i <= n; ++i) f[i] = i;
    return ;
}

int findset(int x) {
    if(f[x] != x) f[x] = findset(f[x]);
    return f[x] ;
}

void unionset(int x, int y) {
    x = findset(x); y = findset(y);
    if(x != y) f[x] = y;
    return ;
}

bool check(int w, int z) {
    makeset();
    for(int i = 1; i <= n+1; ++i) {
        if(i == w || i == z) continue;
        unionset(u[i], v[i]);
    }
    for(int i = 2; i <= n; ++i) if(findset(1) != findset(i))
            return false;
    return true;
}

int main()
{
    int T;
    rd(T);
    while(T--) {
        rd(n);
        for(int i = 1; i <= n+1; ++i) rd(u[i]), rd(v[i]);
        int ans = 0;
        for(int i = 1; i <= n+1; ++i) ans += check(i, 0);
        for(int i = 1; i <= n+1; ++i) for(int j = i+1; j <= n+1; ++j)
            ans += check(i, j);
        printf("%d\n", ans);
    }
    return 0;
}

/**
int g[N][N];
int n;

int u[N], v[N];

bool bfs() {
    bool visit[N];
    queue<int > q;
    while(!q.empty()) q.pop();
    memset(visit, false, sizeof visit);
    q.push(1);
    visit[1] = 1;
    int ans = 1;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = 1; i <= n; ++i) {
            if(i == t) continue;
            if(g[t][i] && !visit[i]) {
                q.push(i);
                visit[i] = true;
                ++ans;
            }
        }
    }
    return ans == n;
}

void solve() {
    int ans = 0;
    for(int i = 0, b, c; i < n+1; ++i) {
        if(i) {
            b = u[i]; c = v[i];
            g[b][c]--; g[c][b]--;
        }
        for(int j = i+1; j <= n+1; ++j) {
            b = u[j]; c = v[j];
            g[b][c]--; g[c][b]--;
            ans += bfs();
            g[b][c]++; g[c][b]++;
        }
        if(i) {
            b = u[i]; c = v[i];
            g[b][c]++; g[c][b]++;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int T;
    rd(T);
    while(T--) {
        rd(n);
        memset(g, 0, sizeof g);
        for(int i = 1; i <= n+1; ++i) {
            rd(u[i]); rd(v[i]);
            int b = u[i], c = v[i];
            g[b][c]++; g[c][b]++;
        }
        solve();
    }
    return 0;
}

**/
