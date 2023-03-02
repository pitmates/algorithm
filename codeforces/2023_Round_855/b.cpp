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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        map<char, int> mpc;
        int ans = 0;
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') {
                if (mpc[c] < 0) ++ans;
                mpc[c]++;
            }
            else {
                c = c - 'A' + 'a';
                if (mpc[c] > 0) ++ans;
                mpc[c]--;
            }
        }
        int res = 0;
        for (auto [c, t] : mpc) {
            t = abs(t) / 2;
            res += t;
        }
        // cout << ans << " , " << res << endl;
        if (m > res) ans += res;
        else ans += m;
        cout << ans << endl;
    }

    return 0;
}