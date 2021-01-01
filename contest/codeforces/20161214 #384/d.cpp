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
const int N = 200020;

vector<int > E[N];
ll ple[N];
ll dp[N];
int n;
ll ans;

void dfs(int u, int p) {
	for(int v : E[u]) if(v != p) {
		dfs(v, u);
		ple[u] += ple[v];
		if(dp[u] != -INF) ans = max(ans, dp[u] + dp[v]);
		dp[u] = max(dp[u], dp[v]);
	}
	dp[u] = max(dp[u], ple[u]);
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) cin >> ple[i], dp[i] = -INF;
	int x, y;
	rep(i, 1, n) {
		cin >> x >> y;
		E[x].pb(y); E[y].pb(x);
	}
	ans = -INF;
	dfs(1, 0);
	if(ans == -INF) cout << "Impossible";
	else cout << ans;
	return 0;
}
