#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    // a > bx > a-b => a/b > x > a/b -1
    // bx + x = a => x = a / (b+1)

    int T; cin >> T;
    while (T--) {
        ll x, y;
        cin >> x >> y;
        ll ans = 0;
        for (int i = 1; i * i <= x; ++i) {
            ans += max(0LL, min(y, x/i-1)-i);
        }
        cout << ans << endl;
    }

    return 0;
}
