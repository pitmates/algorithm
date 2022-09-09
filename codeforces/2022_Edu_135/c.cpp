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
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        sort (a.begin(), a.end());
        sort (b.begin(), b.end());
        int x = 0, y = 0;
        vector<int> c(n), d(n);
        int u = 0, v = 0;
        while (x < n && y < n) {
            if (a[x] == b[y]) { x++; y++; }
            else if (a[x] > b[y]) d[v++] = b[y++];
            else c[u++] = a[x++];
        }

        if (x < n) {
            for (int i = x; i < n; ++i) c[u++] = a[i];
        }

        if (y < n) {
            for (int i = y; i < n; ++i) d[v++] = b[i];
        }

        int res = 0;

        // for (int i = 0; i < u; ++i) cout << c[i] << " "; cout << endl;
        // for (int i = 0; i < v; ++i) cout << d[i] << " "; cout << endl;

        a.resize(u);
        b.resize(u);
        n = u;

        auto calc = [&] (int z) {
            int bit = 0;
            while (z) {
                bit ++;
                z /= 10;
            }
            return bit;
        };

        for (int i = 0; i < u; ++i) {
            if (c[i] < 10) a[i] = c[i];
            else a[i] = calc(c[i]), res++;
            if (d[i] < 10) b[i] = d[i];
            else b[i] = calc(d[i]), res++;
        }

        // for (int i = 0; i < n; ++i) cout << a[i] << "   "; cout << endl;
        // for (int i = 0; i < n; ++i) cout << b[i] << "   "; cout << endl;
         

        sort (a.begin(), a.end());
        sort (b.begin(), b.end());
        x = 0, y = 0;
        u = 0, v = 0;
        while (x < n && y < n) {
            if (a[x] == b[y]) { x++; y++; }
            else if (a[x] > b[y]) d[v++] = b[y++];
            else c[u++] = a[x++];
        }

        if (x < n) {
            for (int i = x; i < n; ++i) c[u++] = a[i];
        }

        if (y < n) {
            for (int i = y; i < n; ++i) d[v++] = b[i];
        }

        a.resize(u);
        b.resize(u);
        n = u;

        for (int i = 0; i < u; ++i) {
            if (c[i] < 2) a[i] = c[i];
            else a[i] = calc(c[i]), res++;
            if (d[i] < 2) b[i] = d[i];
            else b[i] = calc(d[i]), res++;
        }

        cout << res << endl;
    }


    return 0;
}