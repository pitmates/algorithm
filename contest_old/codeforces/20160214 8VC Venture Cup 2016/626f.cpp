#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const  ll MOD = 1e9+7;
const  int N = 233;
const  int M = 1023;

int a[N];
int n, m;
ll dp[N][M], f[N][M];

inline void upd(ll& x, ll y) { x = (x+y) % MOD;}

void solve() {
    int now = 0, i, j, k, w;
    ll t;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1LL;
    for(i = 1; i <= n; ++i) {
        memset(f, 0, sizeof f);
        for(j = 0; j < i; ++j) {
            for(k = 0; k <= m; ++k){
                if(t = dp[j][k]) {
                    w = j * (a[i] - a[i-1]) + k;
                    if(w > m) continue;
                    //one
                    upd(f[j][w], t);
                    //new
                    upd(f[j+1][w], t);
                    //close
                    if(j) upd(f[j-1][w], t*j % MOD);
                    //add to j
                    upd(f[j][w], t*j % MOD);
                }
            }
        }
        for(j = 0; j <= n; ++j) for(k = 0; k <= m; ++k) dp[j][k] = f[j][k];
    }
    ll ans = 0LL;
    for(i = 0; i <= m; ++i) upd(ans, dp[0][i]);
    printf("%I64d\n", ans);
    return;
}

int main()
{
#ifdef PIT
    freopen("626f.in", "r", stdin);
#endif //PIT
    while (scanf("%d %d", &n, &m) != EOF) {
        for(int i = 1; i <= n; ++i) scanf("%d", a+i);
        sort(a+1, a+1+n);
        a[0] = 0;
        solve();
    }
    return  0;
}
