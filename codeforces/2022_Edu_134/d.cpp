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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<int> c(n), d(n);
        int res = 0;
        for (int i = 30; i >= 0; --i) {
            res ^= 1 << i;
            for (int j = 0; j < n; ++j) {
                c[j] = a[j] & res;
                d[j] = (b[j] & res) ^ res;
            }
            sort(c.begin(), c.end());
            sort(d.begin(), d.end());
            
            if (c != d) res ^= 1 << i;
        }
        cout << res << endl;
    }

    return 0;
}