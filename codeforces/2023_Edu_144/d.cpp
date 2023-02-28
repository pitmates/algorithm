#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll M = 998244353;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);
        vector<vector<ll>> dp(n+1, vector<ll> (k+1, -INF));
        for (int i = 0; i < n; ++i) cin >> a[i];
        dp[0][0] = 0;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k && j <= i; ++j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i-1] - x);
                if (j) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i-1] + x);
                dp[i][j] = max(0LL, dp[i][j]);
                if (k-j <= n-i) ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}