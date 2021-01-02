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
const int N = 203;

int g[N][N];
int n, m, r;

vector<int > v;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> r;
	rep(i, 0, N) rep(j, 0, N) {
		if(i == j) g[i][j] = 0;
		else g[i][j] = inf;
	}
	v.clear();
	rep(i, 0, r) {
		int x;
		cin >> x;
		v.pb(x);
	}
	rep(i, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = c;
	}
	rep(k, 1, 1+n) rep(i, 1, 1+n) rep(j, 1, 1+n) {
		g[i][j] = min(g[i][k]+g[k][j], g[i][j]);
	}
	sort(v.begin(), v.end());
	int res = inf;
	do {
		int mx = 0, ans = 0;
		rep(i, 1, r) {
			ans += g[v[i]][v[i-1]];
			mx = max(mx, g[v[i]][v[i-1]]);
		}
		res = min(res, ans);
	}while(next_permutation(v.begin(), v.end()));

	cout << res << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
