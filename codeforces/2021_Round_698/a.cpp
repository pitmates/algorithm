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
        int n, x, now = 1, tmp, mx = 0;
        cin >> n;
        cin >> x;
        tmp = x;
        for (int i = 1; i < n; ++i) {
            cin >> x;
            if (tmp == x) {
                ++now;
            }
            else {
                mx = max(mx, now);
                now = 1;
                tmp = x;
            }
        }
        cout << max(mx, now) << endl;
    }

    return 0;
}
