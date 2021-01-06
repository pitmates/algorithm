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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    map<int, int> ma;
    while (T--) {
        int n;
        cin >> n;
        ma.clear();
        for (int i = 0; i < n; ++i) {
            int x, y = 1;
            cin >> x;
            for (int j = 2; j * j <= x; ++j) {
                int z = 0;
                while (x % j == 0) {
                    x /= j;
                    z ^= 1;
                }
                if (z) y *= j;
            }
            y *= x;
            ma[y] ++;
        }
        int mx = 0, res = 0;
        for (auto z : ma) {
            int x = z.first, y = z.second;
            mx = max(mx, y);
            if (y % 2 == 0 || x == 1) {
                res += y;
            }
        }
        res = max(res, mx);

        int Q;
        cin >> Q;
        while (Q--) {
            ll w;
            cin >> w;
            if (!w) cout << mx << endl;
            else cout << res << endl;
        } 

    }

    return 0;
}
