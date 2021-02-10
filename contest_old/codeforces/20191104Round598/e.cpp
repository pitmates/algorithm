//
// coded by lp.z
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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    std::cin >> n;
    vector<pii > a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    vector<int > dp(n+1, inf);
    dp[0] = 0;

    sort(a.begin(), a.end());
    vector<int > part(n+1, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 3; j < 6 && i+j <= n; ++j) {
            int tmp = dp[i] + a[i+j-1].first - a[i].first;
            if (dp[i+j] > tmp) {
                dp[i+j] = tmp;
                part[i+j] = i;
            }
        }
    }

    int cur = n, now = 1;

    vector<int > ans(n, 0);
    while (cur != 0) {
        for (int i = cur-1; i >= part[cur]; --i) {
            ans[a[i].second] = now;
        }
        now++;
        cur = part[cur];
//        cout << cur << "  ----" << endl;
    }

    cout << dp[n] << " " << now-1 << endl;
    for (int i = 0; i < n; ++i) cout << ans[i] << " "; cout << endl;



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
