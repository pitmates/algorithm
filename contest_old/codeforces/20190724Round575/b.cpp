//
// coded by zhuangliupeng
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

    int T;
    for (cin >> T; T; T--) {
        int n, k;
        cin >> n >> k;
        vector<ll > a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int > id;
        ll res = 0;
        int t = 0, ix = 0;
        for (int i = 1; i <= n; ++i) {
            if (t == k-1) break;
            res += a[i];
            if (res & 1) {
                id.push_back(i);
                res = 0;
                ++t;
                ix = i;
            }
        }
        if (t == k-1 && ix != n) {
            res = 0;
            for (int i = ix+1; i <= n; ++i) res += a[i];
            if (res & 1) {
                cout << "YES" << endl;
                for (auto & x : id) cout << x << " ";
                cout << n << endl;
            }
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
