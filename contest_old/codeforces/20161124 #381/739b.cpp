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

#define pli pair<long long, int >
using namespace std;
const int N = 200100;

vector<pii > E[N];
vector<pli > path;
ll a[N], deep[N];
int ans[N], n;


void dfs(int u) {
	ans[u]++;
	int p = lower_bound(path.begin(), path.end(), mp(deep[u]-a[u], -1)) - path.begin() - 1;
	if(p >= 0) ans[path[p].se]--;
	path.pb({deep[u], u});
	for(auto& v:E[u]){
		deep[v.fi] = deep[u] + v.se;
		dfs(v.fi);
		ans[u] += ans[v.fi];
	}
	path.pop_back();
}


int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	rep(i, 1, 1+n) cin >> a[i], ans[i] = 0, deep[i] = 0;
	rep(i, 2, 1+n) {
		int p, w;
		cin >> p >> w;
		E[p].pb({i, w});
	}
	dfs(1);

	rep(i, 1, n+1) cout << ans[i]-1 << " ";
	return 0;
}
