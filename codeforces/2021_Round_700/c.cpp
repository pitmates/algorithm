#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
const int N = 200007;

int main()
{
// freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1), b(n+1);
        vector<int> g(n+1, 0);
        vector<queue<int>> q(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            g[b[i]] = i;
            if(b[i] != a[i]) q[b[i]].push(i);
        }
        vector<int> ans(m+1, 0);
        int c, f = 0;
        for (int i = 1; i <= m; ++i) {
            cin >> c;
            if (!q[c].empty()) {
                ans[i] = q[c].front();
                q[c].pop();
            }
            else if (g[c]) ans[i] = g[c];
            else if (i == m) f = 1;
        }
        for (int i = 1; i <= n; ++i) if (!q[i].empty()) {
            f = 1;
            break;
        }
        if (g[c] == 0) f = 1;
        if (f) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for (int i = 1; i <= m; ++i) {
                if (ans[i] == 0) ans[i] = ans[m];
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        
    }

    return 0;
}
