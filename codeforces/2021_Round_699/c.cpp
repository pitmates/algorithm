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
        vector<int> a(n+1), b(n+1), c(m+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> d;
        map<int, vector<int>> mv, msv;
        vector<int> ids(n+1, 0), isds(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            if (b[i] != a[i]) {
                mv[b[i]].emplace_back(i);
            }
            else {
                msv[b[i]].emplace_back(i);
            }
        }
        int f = 0;
        for (int i = 1; i <= m; ++i) {
            cin >> c[i];
        }
        vector<int> ans(m+1, 0);
        vector<int> pend;
        for (int i = 1; i <= m; ++i) {
            int u = c[i];
            auto z = mv[u];
            int sz = z.size();
            if (sz > 0 && sz > ids[u]) {
                if (f) {
                    for (int x = 0; x < f; ++x) {
                        ans[i-x-1] = z[ids[u]];
                    }
                    f = 0;
                    pend.clear();
                }
                ans[i] = z[ids[u]++];
                
            }
            else {
                auto v = msv[u];
                sz = v.size();
                if (sz > 0 && sz > isds[u]) {
                    if (f) {
                        for (int x = 0; x < f; ++x) {
                            ans[i-x-1] = v[isds[u]];
                        }
                        f = 0;
                        pend.clear();
                    }
                    ans[i] = v[isds[u]++];
                }
                else {
                    f ++;
                    pend.emplace_back(i);
                }
            }
        }
        if (f) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
            cout << endl;
        }

        for (int i = 1; i <= m; ++i) {

        }

        
    }

    return 0;
}
