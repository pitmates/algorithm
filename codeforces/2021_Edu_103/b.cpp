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
        int n, k;
        cin >> n >> k;
        ll res = 0, x, sum;
        cin >> sum;
        for (int i = 1; i < n; ++i) {
            cin >> x;
            if (100 * x <= k * sum) sum += x;
            else {
                ll y = (100 * x - k * sum + k - 1) / k;
                res += y;
                sum += x + y;
            }
        }
        cout << res << endl;
    }

    return 0;
}
