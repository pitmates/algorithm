#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 8;
int n, m;
int f[N][2];

int dg[N];

inline int cal_dg(int x) {
    int len;
    for(len = 0; x; x/=10) dg[len++] = x % 10;
    return len;
}

int dfs(int i, int s, bool e) {
    if(i == -1) return 1;
    if(!e && ~f[i][s]) return f[i][s];
    int u = e ? dg[i] : 9;
    int res = 0;
    for(int k = 0; k <= u; ++k) {
        if(k == 4 || (k == 2 && s)) continue;
        res += dfs(i-1, k == 6, e && (k == u));
    }
    return e ? res : f[i][s] = res;
}

int solve(int x) {
    return dfs(cal_dg(x)-1, 0, 1);
}

int main()
{
#ifdef PIT
freopen("hdu2089.in", "r", stdin);
#endif // PIT
    while(~scanf("%d %d", &n, &m) && (n||m)) {
        memset(f, -1, sizeof f);
        printf("%d\n", solve(m) - solve(n-1));
    }
    return 0;
}
