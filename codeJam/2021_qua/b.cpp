#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int icase = 1; icase <= T; ++icase) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(2, INT_MAX/4));
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'J') {
                if (s[i-1] == 'J') dp[i][0] = dp[i-1][0];
                else if (s[i-1] == 'C') dp[i][0] = dp[i-1][1] + x;
                else {
                    dp[i][0] = min(dp[i-1][0], dp[i-1][1] + x);
                }
            }
            else if (s[i] == 'C') {
                if (s[i-1] == 'J') dp[i][1] = dp[i-1][0] + y;
                else if (s[i-1] == 'C') dp[i][1] = dp[i-1][1];
                else {
                    dp[i][1] = min(dp[i-1][1], dp[i-1][0] + y);
                }
            }
            else {
                if (s[i-1] == 'J') {
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][0]+y;
                }
                else if (s[i-1] == 'C') {
                    dp[i][0] = dp[i-1][1] + x;
                    dp[i][1] = dp[i-1][1];
                }
                else {
                    dp[i][0] = min(dp[i-1][0], dp[i-1][1] + x);
                    dp[i][1] = min(dp[i-1][1], dp[i-1][0] + y);
                }
            }
        }
        cout << "Case #" << icase << ": " << min(dp[n-1][0], dp[n-1][1]) << endl;
    }

    return 0;
}
