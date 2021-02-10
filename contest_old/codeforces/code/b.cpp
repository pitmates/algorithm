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

    int T; cin >> T;
    while (T--) {
        int n, p, k;
        cin >> n >> p >> k;
        vector<int > g(n);
        for (int i = 0; i < n; ++i) cin >> g[i];

        sort(g.begin(), g.end());
        int ans = 0;
        vector<int > sum(n+1, inf+inf);
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (i < k) sum[i] = sum[i-1] + g[i-1];
            else sum[i] = sum[i-k] + g[i-1];
            if (sum[i] <= p) ans = i;
        }
        cout << ans << endl;

    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
