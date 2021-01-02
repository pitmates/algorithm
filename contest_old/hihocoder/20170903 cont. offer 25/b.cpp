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
const int N = 100100;

vector<int > E[N];
int n;
int son[N];

void dfs(int u, int f) {
	if(E[u].size() == 1 && f != u) {
		son[u] = 1;
		return ;
	}
	son[u] = 1;
	for(auto& v : E[u]) if(v != f) {
		dfs(v, u);
		son[u] += son[v]; 
	}
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	zero(son);
	rep(i, 0, 1+n) E[i].clear();
	rep(i, 1, n) {
		int u, v;
		cin >> u >> v;
		E[u].pb(v);
		E[v].pb(u);
	}
	dfs(1, 1);
	// for(int i = 1; i < n; ++i) printf("%d  %d\n", i, son[i]);
	int ans = 0;
	rep(i, 1, 1+n) if(son[i] % 2 == 0) ++ans;
	cout << ans-1 << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
