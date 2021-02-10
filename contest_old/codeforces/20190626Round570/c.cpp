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

    int q; cin >> q;
    for (int ic = 1; ic <= q; ++ic) {
        int k, n, a, b;
        cin >> k >> n >> a >> b;
        if (1LL * b * n >= 1LL * k) {
            cout << -1 << endl;
            continue;
        }
        int l = 0, r = n;
        while (l <= r) {
            int m = (l + r) >> 1;
            ll val = 1LL * m * a + 1LL * (n-m) * b;
            if (val >= 1LL * k) r = m-1;
            else l = m+1;
        }
//        cout << l << "  " << r << endl;
        cout << r << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
