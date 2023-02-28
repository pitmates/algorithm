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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pii> a(n);
        int f = 1, mx = 0, mi = inf;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if (x == 1) f = 0;
            mx = max(x, mx);
            mi = min(x, mi);
            a[i] = {x, i+1};
        }
        if (mx == mi) cout << 0 << endl;
        else if (!f) cout << -1 << endl;
        else {
            int t = 0, m = 30*n;
            vector<pii> ans(m);
            vector<pii> b(n);
            while (t <= m) {
                sort (a.begin(), a.end());
                if (a[0].first == a[n-1].first) break;
                int k = n-1, i = n-1;
                for (; i > 0; --i) {
                    auto [u, v] = a[i];
                    while (k >= 0 && a[k].first >= u) --k;
                    // cout << i << " " << k << " " << t << ": ";
                    if (k < 0) break;
                    auto [x, y] = a[k];
                    int z = (u + x - 1) / x;
                    // cout << u << " " << x << "  " << v << " " << y << "  " << z << endl;
                    b[i] = {z, v};
                    ans[t++] = {v, y};
                }
                for (; i >= 0; --i) b[i] = a[i];
                a = b;
            }
            if (t > m) cout << -1 << endl;
            else {
                cout << t << endl;
                for (int i = 0; i < t; ++i) cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
    }

    return 0;
}