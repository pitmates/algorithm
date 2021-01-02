#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define inf 0x3f3f3f3f
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int k = min({k2, k5, k6});
    int ans = k * 256;
    k2 -= k;
    k = min(k2, k3);
    ans += k * 32;
    cout << ans;
    return 0;
}
