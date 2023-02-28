#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const int M = 998244353;

void solve(int l, int r) {
    if (l + l > r) {
        cout << 1 << " " << (r-l+1) << endl;
        return ;
    }
    int t, n = l;
    for (t = 0; n <= r; ++t) {
        n = n * 2;
    }
    int ans = 0, d = (1<<(t-1));
    int up = r / d;
    ans = up - l + 1;
    // cout << d << " " << up << " " << ans << endl;
    d >>= 1;
    int nr = r / 3;
    int nu = nr / d;
    ans = (ans + 1LL * max(0, (nu - l + 1)) *  (t - 1) % M) % M;
    cout << t << " " << ans << endl;
}

int main()
{
// freopen("./io/a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}
