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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;  cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> c[i];
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) if (a[i] > b[i]) swap(a[i], b[i]);

        reverse(c.begin(), c.end());
        reverse(b.begin(), b.end());
        reverse(a.begin(), a.end());
        
        ll now = c[0]-1, res = 0, mx = 0;
        for (int i = 0; i < n-1; ++i) {
            if (b[i] == a[i]) {
                mx = max(mx, now+2);
                now = c[i+1]-1;
            }
            else {
                ll inner = b[i] - a[i];
                mx = max (mx, now + inner + 2);
                now += c[i+1] + 1 - inner;
                if (now < c[i+1] - 1) now = c[i+1] - 1;
            }
            // cout << " ii  " << i << " " << mx << "  " << now << endl;
        }
        cout << mx << endl;
    }

    return 0;
}
