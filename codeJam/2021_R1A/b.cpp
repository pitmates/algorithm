#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
const int N = 49912;

int dp[2][100][N];


int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int icase = 1; icase <= T; ++icase) {
        cout << "Case #" << icase << ": ";
        int m; cin >> m;
        int sum = 0;
        vector<int> a(123);
        int t = 0;
        for (int i = 0; i < m; ++i) {
            int pi, ni;
            cin >> pi >> ni;
            for (int j = 0; j < ni; ++j) a[t++] = pi;
            sum += pi * ni;
        }

        memset(dp, -1, sizeof dp);
        dp[1][0][0] = dp[1][0][1] = a[0];
        dp[1][1][a[0]] = 0;
        int f = 0;
        
            cout << endl;
            for (int j = 0; j <= t; ++j) {
                for (int k = 0; k <= sum; ++k) cout << " " << dp[1][j][k]; cout << endl;
            }
            cout << endl;

        for (int i = 2; i <= t; ++i) {
            dp[f][0][0] = dp[f][0][1] = dp[f^1][0][0] + a[i-1];
            for (int j = 1; j <= i; ++j) {
                for (int k = 1; k <= sum; ++k) {
                    if (dp[f^1][j][k] != -1) {
                        dp[f][j][k] = max(dp[f^1][j][k] + a[i-1], dp[f][j][k]);
                    }
                    if ( k % a[i-1] == 0 && dp[f^1][j-1][k/a[i-1]] != -1) {
                        dp[f][j][k] = max(dp[f^1][j-1][k/a[i-1]], dp[f][j][k]);
                    }
                }
            }
            cout << endl;
            for (int j = 0; j <= t; ++j) {
                for (int k = 0; k <= sum; ++k) cout << " " << dp[f][j][k]; cout << endl;
            }
            cout << endl;
            f ^= 1;
        }
        int ans = 0;
        for (int i = 0; i < t; ++i) {
            for (int k = 1; k <= sum; ++k) {
                if (dp[f][i][k] == k) {
                    ans = max(ans, k);
                }
            }
        }

        
        cout << ans << endl;
    }

    return 0;
}
