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

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m, 0);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a[i] = x % m;
            b[a[i]]++;
        }
        int ans = b[0] > 0;
        // cout << "0: " << ans << endl;
        for (int i = 1; i + i <= m; ++i) {
            int y = m - i;
            int mx = max(b[y], b[i]), mi = min(b[y], b[i]);
            if (mi == 0) ans += mx;
            else if (mx == mi) ans += 1;
            else ans += mx - mi ;
            // cout << i << ": " << ans << endl;
        }
        cout << ans << endl;

    }

    return 0;
}
