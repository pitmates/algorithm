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
const int N = 200200;
bool color[N];
int n;
vector<int > E[N];


pii dfs(int u, int parent, int deep) {
	pii res = {deep, u};
	rep(i, 0, sz(E[u])) {
		int v = E[u][i];
		if(v == parent) continue;
		if(color[u] == color[v]) res = max(res, dfs(v, u, deep));
		else res = max(res, dfs(v, u, deep+1));
	}
	return res;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, 1, n+1) cin >> color[i];
	int x, y;
	rep(i, 1, n) {
		cin >> x >> y;
		E[x].pb(y); 
		E[y].pb(x);
	}
	pii ans = dfs(1, -1, 0);
	ans = dfs(ans.se, -1, 0);
	cout << ((ans.fi + 1) >> 1) << endl;
	return 0;
}
