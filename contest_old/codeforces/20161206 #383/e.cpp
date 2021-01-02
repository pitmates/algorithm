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
const int N = 100100;

int b[N], g[N];
int ans[N<<1];
int n;
vector<int > E[N<<1];

void dfs(int x, int y) {
	ans[x] = y;
	for(auto v : E[x]) if(!ans[v]){
		dfs(v, 3-y);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, 1, n+1) {
		cin >> b[i] >> g[i];
		E[b[i]].pb(g[i]);
		E[g[i]].pb(b[i]);
		E[i+i-1].pb(i+i);
		E[i+i].pb(i+i-1);
	}
	zero(ans);
	rep(i, 1, (n<<1|1)) if(!ans[i]) dfs(i, 1);
	rep(i, 1, n+1) cout << ans[b[i]] << " " << ans[g[i]] << endl;
	return 0;
}
