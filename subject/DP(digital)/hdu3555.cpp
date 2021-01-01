#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 20;

int dg[N];
ll f[N][2];

ll dfs(int i, int s, int e) {
    if(i == -1) return 1LL;
    if(!e && ~f[i][s]) return f[i][s];
    ll res = 0;
    int u = e ? dg[i] : 9;
    for(int d = 0; d <= u; ++d) {
        if(d == 9 && s) continue;
        res += dfs(i-1, d==4, e&&(d==u));
    }
    return e ? res : f[i][s] = res;
}

ll solve(ll n) {
    int len;
    for(len = 0; n; n/=10) dg[len++] = n % 10;
    memset(f, -1, sizeof f);
    return dfs(len-1, 0, 1);
}

int main()
{
#ifdef PIT
freopen("hdu3555.in", "r", stdin);
#endif // PIT
    int T;
    scanf("%d", &T);
    while(T--) {
        ll n;
        scanf("%I64d", &n);
        printf("%I64d\n", n + 1 - solve(n));
    }
    return 0;
}
