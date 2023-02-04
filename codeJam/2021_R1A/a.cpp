#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int calc(string& s, string t) {
    int n = s.size(), m = t.size();
    if (n > m) return 0;
    int f = -1, g = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] > t[i]) { f = i; break; }
        if (t[i] > s[i]) { g = i; break; }
    }
    if (f > -1) {
        for (int i = n; i < m; ++i) s += '0';
        return m - n;
    }
    if (g != -1) {
        for (int i = n; i <= m; ++i) s += '0';
        return m - n + 1;
    }
    for (int i = m-1; i >= n; --i) {
        if (t[i] != '9') { f = i; break; }
    }
    if (f != -1) {
        for (int i = n; i < f; ++i) s += t[i];
        s += (t[f] + 1);
        for (int i = f+1; i < m; ++i) s += '0';
        return m - n;
    }

    for (int i = n; i <= m; ++i) s += '0';
    return m - n + 1;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T, ic = 1; cin >> T;
    for (; ic <= T; ++ic) {
        int n; cin >> n;
        vector<string> x(n);
        for (int i = 0; i < n; ++i) {
            int y; cin >> y;
            x[i] = to_string(y);
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += calc(x[i], x[i-1]);
        }
        // for (int i = 0; i < n; ++i) cout << x[i] << " "; cout << endl;
        cout << "Case #" << ic << ": " << ans << endl;
    }

    

    return 0;
}
