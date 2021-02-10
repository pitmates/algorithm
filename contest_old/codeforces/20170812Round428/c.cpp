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

double to[N], next[N];
int rnk[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	// ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	scanf("%d", &n);
	rep(i, 1, n) {
		int u, v;
		scanf("%d %d", &u, &v);
		E[u].pb(v);
		E[v].pb(u);
	}
	// puts("ssss");
	// to.clear();
	// next.clear();
	zerox(rnk, -1);
	to[1] = 1.0;
	queue<int > q;
	while(!q.empty()) q.pop();
	q.push(1);
	rnk[1] = 0;
	double ans = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		int sz = sz(E[u]);
		double z;
		if(sz == 1) z = 1.0, ans += rnk[u] * to[u];
		else {
			if(u == 1) z = 1. / sz;
			else z = 1. / (sz - 1);
		}
		// printf("%d  %.2f %d\n", u, z, sz);
		for(auto& v : E[u]) if(v != u && rnk[v] == -1){
			q.push(v);
			rnk[v] = rnk[u] + 1;
			to[v] = to[u] * z;
		}
	}
	printf("%.10f\n", ans);
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
