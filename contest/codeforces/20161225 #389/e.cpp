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
const int N = 1e6+1;
const int M = 1e7+1;

int g[N], dp[M];
int n, k, mx;

bool binsearch(int mid) {
	rep(i, mid, mx+1) {
		int hf = (i>>1);
		if(hf < mid) dp[i] = 1;
		else dp[i] = dp[hf] + dp[i-hf];
	}
	ll s = 0;
	rep(i, 0, n) if(g[i] >= mid) s += dp[g[i]];
	return s >= k;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	ll ans = 0;
	mx = 0;
	rep(i, 0, n) {
		cin >> g[i];
		ans += g[i];
		mx = max(mx, g[i]);
	}
	if(ans < (ll)k) {
		cout << -1;
		return 0;
	}
	int l = 1, r = M, mid;
	while(l+1 < r) {
		mid = (l+r) >> 1;
		if(binsearch(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}
