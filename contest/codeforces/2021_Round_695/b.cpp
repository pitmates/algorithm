#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int check(int x, vector<int>& v) {
    if (x == 0 || x == v.size()-1) return 0;
    if (v[x] > v[x-1] && v[x] > v[x+1]) return 1;
    if (v[x] < v[x-1] && v[x] < v[x+1]) return 1;
    return 0;
}

int main()
{
// freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<bool> g(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (check(i, a)) g[i] = true, res ++;
        }

        int  mi = 0;
        for (int i = 1; i < n-1; ++i) {
            if (g[i]) {
                int t = a[i];
                int q = check(i-1, a) + check(i, a) + check(i+1, a), mt = q;
                a[i] = a[i-1];
                mt = min(check(i-1, a) + check(i, a) + check(i+1, a), mt);
                a[i] = a[i+1];
                mt = min(check(i-1, a) + check(i, a) + check(i+1, a), mt);
                a[i] = t;
                mi = max(mi, q-mt);
                // printf("%d %d %d  %d\n", i, q, mt, mi);
            }
        }
        
        cout << res - mi  << endl;
    }

    return 0;
}
