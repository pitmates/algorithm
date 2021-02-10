//
// Created by pitmates on 2019-06-03.
//

#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const ll mo = (ll)1e9+7;

const int N = 1e6+7;

ll dp[2][21][2];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    zero(dp);

    int k, f = 1;
    for (int i = 1; i < 21; ++i) if ((1<<i) <= n) k = i;
    dp[f][k][0] = 1;
    if ((1 << (k-1)) * 3 <= n) dp[f][k-1][1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int x = 0; x <= k; ++x){
            for (int y = 0; y < 2; ++y) {
                int e2 = (1 << x), e3 = y == 0 ? 1 : 3;
                dp[f^1][x][y] = (dp[f^1][x][y] + dp[f][x][y] * (n/(e2*e3) - i)) % mo;
                if (x) dp[f^1][x-1][y] = (dp[f^1][x-1][y] + dp[f][x][y] * (n/(e2/2*e3) - n/(e2*e3))) % mo;
                if (y) dp[f^1][x][y-1] = (dp[f^1][x][y-1] + dp[f][x][y] * (n/e2 - n/(e2*e3))) % mo;
            }
        }
        f ^= 1;
        zero(dp[f^1]);
    }
    cout << dp[f][0][0]  << endl;



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
