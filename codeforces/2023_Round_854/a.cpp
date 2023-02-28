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
        vector<int> p(m), vis(n+m+1, 0), a(n, -1);
        for (int i = 0; i < m; ++i) cin >> p[i];
        int t = n-1;
        for (int i = 0; i < m; ++i) {
            if (vis[p[i]]) continue;
            vis[p[i]] = 1;
            if (t >= 0) a[t--] = i+1;
        }
        
        for (int i = 0; i < n; ++i) cout << a[i] << " "; cout << endl;
    }

    return 0;
}