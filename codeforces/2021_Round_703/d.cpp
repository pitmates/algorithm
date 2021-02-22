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

    int n, k;
    cin >> n >> k;
    vector<int> a(1+n);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    auto calc = [&](int m) {
        vector<int> sum(n+1, 0);
        int mi = inf, ma = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] < m) sum[i] = sum[i-1] - 1;
            else sum[i] = sum[i-1] + 1;
        }
        for (int i = k; i <= n; ++i) {
            mi = min(mi, sum[i-k]);
            ma = max(ma, sum[i]-mi);
        }
        return ma > 0;
    };

    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (calc(m)) l = m + 1;
        else r = m-1;
    }
    cout << r << endl;

    return 0;
}
