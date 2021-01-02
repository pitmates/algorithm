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
const int N = 3e5+7;

vector<pii > E[N];
vector<int > edge;
int n, m;
int d[N], g[N];

int dfs(int u) {
	int du = d[u];
	g[u] = 1;
	for(auto& v : E[u]) if(!g[v.fi]) {
		if(dfs(v.fi)) {
			edge.pb(v.se);
			du ^= 1;
		}
	}
	return du;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int ok = 0, x, h = 0, xr = 0;
	rep(i, 1, 1+n) {
		cin >> x;
		if(x == -1) {
			if(ok) d[i] = 0;
			else ok = 1, h = i;
		}
		else d[i] = x, xr ^= x;
	}
	rep(i, 1, 1+m) {
		int u, v;
		cin >> u >> v;
		E[u].pb({v, i});
		E[v].pb({u, i});
	}
	if(!ok && xr) cout << -1 << endl; 
	else {
		d[h] = xr;
		zero(g);
		dfs(h ? h : 1);
		cout << sz(edge) << endl;
		for(int v:edge) cout << v << " ";
	}

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
