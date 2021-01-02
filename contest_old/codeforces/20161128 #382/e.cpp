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
const ll mo = (ll)1e9+7;
const int N = 103;
const int M = 43;

vector<int > E[N];
ll dp[N][M];
ll f[M];
int n, k;

void dfs(int u, int fa) {
	dp[u][0] = dp[u][k+1] = 1;
	for(auto v : E[u]) if(v != fa) {
		dfs(v, u);
		zero(f);
		rep(i, 0, k+k+1) rep(j, 0, k+k+1){
			if(i+j <= k+k) (f[min(i, 1+j)] += dp[u][i] * dp[v][j] % mo) %= mo;
			else (f[max(i, 1+j)] += dp[u][i] * dp[v][j] % mo) %= mo;
		}
		rep(i, 0, k+k+1) dp[u][i] = f[i];
	}
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int u, v;
	rep(i, 0, n+1) E[i].clear();
	rep(i, 1, n) {
		cin >> u >> v;
		E[u].pb(v); E[v].pb(u);
	}
	zero(dp);
	dfs(1, 0);
	ll ans = 0;
	rep(i, 0, k+1) (ans += dp[1][i]) %= mo;
	cout << ans << endl;
	return 0;
}
