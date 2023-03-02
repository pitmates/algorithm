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
    int n;
    cin >> n;
    int m = (1 << 26) - 1;
    vector<int> xb(n), vb(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (auto c : s) {
            int ci = c - 'a';
            xb[i] ^= (1 << ci);
            vb[i] |= (1 << ci);
        }
    }

    ll ans = 0;
    for (int i = 0; i < 26; ++i) {
        vector<int> cnt(m+1, 0);
        for (int j = 0; j < n; ++j) if (!(vb[j] & (1 << i))) {
            ans += cnt[(1 << i) ^ m ^ xb[j]];
            ++cnt[xb[j]];
        }
    }
    cout << ans << endl;

    return 0;
}