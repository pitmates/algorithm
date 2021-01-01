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
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

ll n, m;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	if(m >= n) {
		cout << n;
		return 0;
	}
	ll ans = m;
	ll l = 0, r = (ll)1e10, k;
	while(l <= r) {
		k = (l + r) >> 1;
		if(ans+k <= n-(k-1)*k/2) l = k+1;
		else r = k-1;
//printf("%I64d %I64d %I64d %I64d %I64d %I64d\n", ans, k, ans+k, n-(k-1)*k/2, l, r);
	}
	if(ans+r < n-(r-1)*r/2) cout << ans+r+1;
	else cout << ans+r;
	return 0;
}
