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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, x;
        ll y;
        cin >> n >> x;
        ll minv = 0, maxv = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> y;
            maxv += (y + x - 1) / x;
            sum += y;
        }
        minv = (sum + x - 1) / x;
        cout << minv << " " << maxv << endl;
    }

    return 0;
}
