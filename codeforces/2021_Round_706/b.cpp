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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> m;
        int miss = -1, mx = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            m[a[i]] = 1;
        }
        n = m.size();
        if (k == 0) {
            cout << n << endl;
            continue;
        }
        int t = 0;
        for (auto z : m) {
            if (z.first != t && miss == -1) {
                miss = t;
            }
            mx = max(mx, z.first);
            ++t;
        }
        if (miss == -1) miss = mx + 1;
        // cout << miss << " " << mx << endl;
        if (miss == mx + 1) {
            cout << (n + k) << endl;
        }
        else {
            int d = (mx + miss + 1) / 2;
            if (m[d] > 0) cout << n << endl;
            else cout << (n+1) << endl;
        }


    }

    return 0;
}
