#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int mo = 1e9+7;
const int N = 202;

int dp[N][N][N];
int n, p;

inline void add(int &a, int b) { if((a += b) >= mo) a -= mo; }

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    ios_base::sync_with_stdio(false);

    cin >> n;
    dp[0][0][0] = 1;
    rep(i, 1, n) {
        cin >> p;
        rep(j, 0, i) rep(k, 0, i) {
                add(dp[i][j+1][k], 1ll*(1000-p)*dp[i-1][j][k] % mo);
                add(dp[i][j][max(k+1, j+1)], 1ll*p*dp[i-1][j][k] % mo);
            }
    }
    int ans = 0;
    rep(i, 0, n) rep(j, 0, n) add(ans, 1ll*dp[n][i][j] * max(i, j) % mo);
    cout << ans << endl;
    return 0;
}
