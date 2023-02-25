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
        vector<ll> a(n+1), b(n+1, 0), c(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            b[i] += b[i-1];
        }
        
        vector<pii> v(n+1, {0, 0});
        for (int i = 1; i <= n; ++i) {
            ll x = a[i] + b[i-1];
            int d = lower_bound(b.begin(), b.end(), x) - b.begin();
            if (d > i) {
                v[i].first++;
                v[d-1].second++;
            }
            // cout << i <<  "+" << d << " " << x << " " << b[i] << " " << b[i-1] << endl;
            if (d < n+1) c[d] += x - b[d-1];
        }
        int res = 0;
        // for (int i = 1; i <= n; ++i) cout << c[i] << ", "; cout << endl;
        // for (int i = 1; i <= n; ++i) cout << b[i] << "- "; cout << endl;
        vector<ll> ans(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            res += v[i].first;
            ans[i] = res * (b[i] - b[i-1]) + c[i];
            res -= v[i].second;
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << " "; cout << endl;
    }


    return 0;
}