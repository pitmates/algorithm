//
// Created by pitmates on 2018/11/23.
//

#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 123456;

ll a[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans += a[i];
    }
    a[0] = 0;
    sort(a, a+n+1);
    ans -= n;
    for (int i = n-1; i >= 0; --i) {
        ll y = a[i+1] - a[i];
        if (y > 1) ans -= y - 1;
        else a[i] = max(1LL, a[i+1] - 1);
    }
    if (n == 1) ans = 0;
    cout << ans << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
