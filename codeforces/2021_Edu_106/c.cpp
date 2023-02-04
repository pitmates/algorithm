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
// freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m = n/2, mm = n-m;
        vector<ll> h(m+1), r(mm);
        int ht = 0, rt = 0;
        for (int i = 0; i < n; ++i) {
            ll x; cin >> x;
            if (i&1) h[ht++] = x;
            else r[rt++] = x;
        }
        
        ll ans = INF;
        ll min_r = INF, min_h = INF;
        ll sum_r = 0, sum_h = 0;
        ll res_r = 0, res_h = 0;
        for (int i = 0; i < rt; ++i) {
            min_r = min(min_r, r[i]);
            sum_r = sum_r + r[i];
            res_r = min_r * (n-i) + sum_r - min_r;
            if (i > 0) {
                ans = min(ans, res_r + res_h);
            }
            if (i < ht) {
                min_h = min(min_h, h[i]);
                sum_h = sum_h + h[i];
                res_h = min_h * (n-i) + sum_h - min_h;
                ans = min(ans, res_h + res_r);
            }
        }
        cout << ans << endl;

    }

    return 0;
}
