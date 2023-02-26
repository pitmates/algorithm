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
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1);
        vector<int> b(n+m+1), c(n+m+1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            b[a[i]] = 0;
        }
        
        for (int i = 1; i <= m; ++i) {
            int x, y;
            cin >> x >> y;
            c[a[x]] += i - b[a[x]];
            a[x] = y;
            b[a[x]] = i;
        }
        for (int i = 1; i <= n; ++i) c[a[i]] += m + 1 - b[a[i]];

        ll ans = 0;
        // for (int i = 0; i < n+m+1; ++i) cout << c[i] << " "; cout << endl;
        for (int i = 0; i < n+m+1; ++i) {
            ans += 1LL * m * (m + 1) - 1LL * (m - c[i]) * (m - c[i] + 1);
        }
        cout << ans / 2 << endl;
    }
    return 0;
}

/*
1
3 3
1 2 3
1 4
2 5
1 4
*/