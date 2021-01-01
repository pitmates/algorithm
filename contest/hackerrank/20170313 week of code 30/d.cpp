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
#define pli pair<ll, int >

using namespace std;
const int N = 5005;

ll ans[N][N];
ll dp[N][N];
int n, state;
pii p[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> state;
	int x, w;
	rep(i, 1, 1+n) {
		cin >> x >> w;
		p[i] = {x, w};
	}
	zero(ans);
	rep(i, 1, 1+n) ans[i][1] = ans[i-1][1] + p[i].se*(p[i].fi-p[1].fi);
	if(state == 1) {
		cout << ans[n][1] << endl;
		return 0;
	}
	if(state == 2) {
		ll miv = INF;
		rep(i, 2, 1+n) {
			ll s = ans[i-1][1];
			rep(j, i+1, 1+n) s += p[j].se*(p[j].fi-p[i].fi);
			miv = min(miv, s);
		}
		cout << miv << endl;
		return 0;
	}
	rep(i, 3, 1+state) {
		int l = i-1;
		rep(lo, i, 1+n) {
			while()
			dp[i][j] += dp[k][j-1];
		}
		
	}
	ll res = INF;
	rep(i, state, 1+n) {
		ll x = dp[i][state];
		rep(j, i+1, 1+n) x += p[j].se*(p[j].fi-p[i].fi);
		res = min(x, res);
	}
	cout << res << endl;
	return 0;
}
