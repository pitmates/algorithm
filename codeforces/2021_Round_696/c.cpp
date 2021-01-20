/**/
#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
const int N = 1000007;

int main()
{
// freopen("a.in", "r", stdin);
// freopen("a1.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> a(2*n);
        unordered_map<int, int> g; g.clear();
        for (int i = 0; i < 2*n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<pair<int, int>> ans;
        int flag = 0;
        for (int i = 2*n-2; i >= 0; --i) {
            int x = a[2*n-1] + a[i];
            // cout << i << "  x: " << x << endl;
            for (int j = 0; j < 2*n; ++j) g[a[j]]++;
            for (int j = 2*n-1; j >= 0; --j) {
                int p = a[j], q = x - p;
                // cout << " " << p << " " << g[p] << "   " << q << " " << g[q] << endl;
                if (p >= x || g[p] == 0) continue;
                g[p]--;
                if (g[q] == 0) break;
                ans.push_back({p, q});
                g[p]--;
                g[q]--;
                x = p;
                // cout << " " << p << "   " << q <<  endl;
            }
            if (ans.size() == n) {
                flag = 1;
                break;
            }
            g.clear();
            ans.clear();
        }
        if (flag == 0) cout << "NO" << endl;
        else {
            cout << "YES\n" << ans[0].second + ans[0].first << endl;
            for (auto z : ans) cout << z.first << " " << z.second << endl;
        }
    }

    return 0;
}
