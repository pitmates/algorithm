#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll M = 998244353;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int eqo = 0, eqt = 0;
        int t = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) {
                t++;
            }
            else {
                eqo += max(0, t-2);
                t = 1;
            }
        }
        eqo += max(0, t-2);
        
        for (int i = 2; i < n; ++i) {
            if (s[i] != s[i-1] && s[i] == s[i-2]) {
                eqt += 1;
            }
        }
        // cout << eqo << " " << eqt << " --" << endl;
        int ans = n - (eqt + eqo) - 1;
        cout << ans << endl;
    }
    return 0;
}