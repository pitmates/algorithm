#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const int N = 2020;

ll f[20][20][N];
int dg[20];

ll dfs(int i, int o, int s, bool e) {
    if(i == -1) return s == 0;
    if(s < 0) return 0;
    if(!e && ~f[i][o][s]) return f[i][o][s];
    int u = e ? dg[i] : 9;
    ll res = 0;
    for(int d = 0, t = s; d <= u; ++d, t = s) {
        t += (i - o) * d;
        res += dfs(i-1, o, t, e && d==u);
    }
    return e ? res : f[i][o][s] = res;
}

ll solve(ll n) {
    int len = 0;
    for( ; n; n /= 10) dg[len++] = n % 10;
    memset(f, -1, sizeof f);
    ll res = 0LL;
    for(int i = 0; i < len; ++i)
        res += dfs(len-1, i, 0, 1);
    return res - len + 1;
}

int main()
{
#ifdef PIT
freopen("hdu3709.in", "r", stdin);
#endif // PIT
    int T;
    scanf("%d", &T);
    while(T--) {
        ll x, y;
        scanf("%I64d %I64d", &x, &y);
        printf("%I64d\n", solve(y) - solve(x-1));
    }
    return 0;
}
