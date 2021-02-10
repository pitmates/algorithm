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
const int N = 1010;

int node[N][5];
int n;

void solve() {
	if(n > 16) {
		cout << 0 << endl;
		return ;
	}
	if(n < 3) {
		cout << n << endl;
		rep(i, 0, n) cout << i+1 << " ";
		cout << endl;
		return ;
	}
	vector<int > res;
	rep(i, 0, n) {
		int flag = 1;
		rep(j, 0, n) if(j != i) {
			int vx[5];
			rep(u, 0, 5) vx[u] = node[j][u] - node[i][u];
			rep(k, 0, n) if(k != i && k != j) {
				int vy[5];
				rep(u, 0, 5) vy[u] = node[k][u] - node[i][u];
				int ans = 0;
				rep(v, 0, 5) ans += vx[v] * vy[v];
				if(ans > 0) {flag = 0; break; }
			}
			if(flag == 0) break;
		}
		if(flag) res.pb(i+1);
	}
	cout << sz(res) << endl;
	for(int u : res) cout << u << " ";
	cout << endl;
	return ;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 0, n) rep(j, 0, 5) cin >> node[i][j];
	solve();
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
