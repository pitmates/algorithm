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
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        string ans = "";
        int f = 0;
        if (a == b) ans = a, f = 1;
        else if (a[0] == b[0]) ans = a.substr(0, 1) + "*", f = 1;
        else if (a[n-1] == b[m-1]) ans = "*" + a.substr(n-1, 1), f = 1;
        else {
            for (int i = 1; i < n && !f; ++i) {
                for (int j = 1; j < m; ++j) {
                    if (a[i] == b[j] && a[i-1] == b[j-1]) {
                        ans = "*" + a.substr(i-1, 2) + "*";
                        f = 1;
                        break;
                    }
                }
            }
        }
        if (!f) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << ans << endl;
        }
    }

    return 0;
}