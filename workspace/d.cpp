#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


void solve(int n, int m)
{
    vector<int> a(n);
    cin >> a[0];
    int mx = a[0], mi = a[0];
    ll dist = 0;

    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mi = min(mi, a[i]);
        dist += abs(a[i] - a[i-1]);
    }

    // cout << mx << "   ==  " << mi << endl;

    if (mx < m) {
        int incD = min(m - a[0], m - a[n-1]);
        for (int i = 1; i < n; ++i) {
            int d = m - a[i-1] + m - a[i] - abs(a[i] - a[i-1]);
            incD = min(d, incD);
        }
        dist += incD;
    }
    if (mi > 1) {
        int incD = min(a[0] - 1, a[n-1] - 1);
        for (int i = 1; i < n; ++i) {
            int d = a[i-1] - 1 + a[i] - 1 - abs(a[i] - a[i-1]);
            incD = min(d, incD);
        }
        dist += incD;
    }
    cout << dist << endl;
    return ;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        solve(n, x);
    }

    return 0;
}
