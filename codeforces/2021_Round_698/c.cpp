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
ll d[N];

int main()
{
// freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m = n + n;
        unordered_map<ll, int> umc;
        umc.clear();
        int f = 1;
        for (int i = 0; i < m; ++i) {
            cin >> d[i];
            umc[d[i]]++;
            if (d[i] & 1) f = 0;
        }
        
        for (auto z : umc) {
            if (z.second & 1) {
                f = 0;
                break;
            }
        }
        if (!f) {
            cout << "NO" << endl;
            continue;
        }
        sort (d, d+m);
        reverse(d, d+m);
        int nn = m;
        ll res = 0;
        vector<ll> a(m);
        // for (int i = 0; i < m; ++i) cout << d[i] << " "; cout << endl;
        for (int i = 0; i < m; i += 2) {
            ll z = d[i] - res;
            if (z % nn || z < 0) {
                f = 0;
                break;
            }
            a[i] = z / nn;
            nn -= 2;
            // cout << i << " -- " << d[i] << " " << res << " " << z  << "  " << a << " " ;
            res += a[i] * 2;
            a[i+1] = -a[i];

            // cout << res << "  ++\n";
        }
        // cout << endl;
        if (!f) cout << "NO" << endl;
        else {
            sort (a.begin(), a.end());
            for (int i = 1; i < m; ++i) {
                if (a[i] == a[i-1]) {
                    f = 0;
                    break;
                }
            }
            if (!f) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        
    }

    return 0;
}
