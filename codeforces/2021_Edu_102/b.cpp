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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        if (s.size() < t.size()) swap(s, t);
        int n = s.size(), m = t.size();
        int g = __gcd(n, m);
        int lcm = n * m / g;
        int nt = lcm / n, mt = lcm / m;
        string l_s = "", l_t = "";
        for (int i = 0; i < nt; ++i) {
            l_s = l_s + s;
        }
        for (int i = 0; i < mt; ++i) {
            l_t = l_t + t;
        }
        if (l_s != l_t) cout << -1 << endl;
        else cout << l_t << endl;

    }

    return 0;
}
