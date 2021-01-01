#include <bits/stdc++.h>

using namespace std;

int dg[10];
int f[10][3][15];
bool first;

int new_s(int s, int d) {
    if(s == 2 || (s == 1 && d == 3)) return 2;
    if(d == 1) return 1;
    return 0;
}

int dfs(int i, int s, int m, bool e) {
    if(i == -1) return m == 0 && s == 2;
    if(!e && ~f[i][s][m]) return f[i][s][m];
    int res = 0;
    int u = e ? dg[i] : 9;
    for(int d = 0; d <= u; ++d) {
        res += dfs(i-1, new_s(s, d), (m*10+d) % 13, e && (d==u));
    }
    return e ? res : f[i][s][m] = res;
}

int solve(int n) {
    int len = 0;
    for( ; n; n /= 10) dg[len++] = n % 10;
    memset(f, -1, sizeof f);
    return dfs(len-1, 0, 0, 1);
}

int main()
{
#ifdef PIT
freopen("hdu3652.in", "r", stdin);
#endif // PIT
    int n;
    while(~scanf("%d", &n)) {
        printf("%d\n", solve(n));
    }
    return 0;
}
