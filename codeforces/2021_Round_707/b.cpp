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
        int n; cin >> n;
        vector<int> a(n, 0);
        int t = 0;
        vector<pii> pa(n<<1);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (!x) continue;
            int y = max(0, i-x+1);
            pa[t++] = {y, 1};
            pa[t++] = {i, -1};
        }
        sort(pa.begin(), pa.begin()+t);
        int l = 0, now = 0;
        for (int i = 0; i < t; ++i) {
            auto z = pa[i];
            while (l < z.first) {
                if (now == 0) a[l++] = now;
                else a[l++] = 1;
            }
            now += z.second;
            if (now == 0) a[l++] = 1;
        }
        for (int i = 0; i < n; ++i) cout << a[i] << " "; cout << endl;
    }

    return 0;
}
