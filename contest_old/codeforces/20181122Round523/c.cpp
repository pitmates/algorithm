//
// Created by pitmates on 2018/11/23.
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
ll mo = (ll)1e9+7;
const int N = 123456;
const int M = 1e6+17;

vector<int > e[M];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 0; i < M; ++i) e[i].clear();
    for (int i = M-1; i > 0; --i) {
        for (int j = i; j < M; j += i) {
            e[j].push_back(i);
        }
    }

    vector<ll > dp(M, 0);
    int n, x;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (auto & z : e[x]) (dp[z] += dp[z-1]) %= mo;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) (ans += dp[i]) %= mo;
    cout << ans << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
