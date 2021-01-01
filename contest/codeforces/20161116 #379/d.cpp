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

ll dis[3][3];
char c[3][3];

void init() {
	rep(i, 0, 3) rep(j, 0, 3) {
		c[i][j] = 'W';
		dis[i][j] = INF;
	}
}

int n, x, y;

int f(ll w) {
	if(w < 0) return 0;
	if(w == 0) return 1;
	return 2;
}

pii deal(int u, int v) {
	ll a = 1LL*x-u, b = 1LL*y - v;
	if(abs(a) == abs(b) || !a || !b) return {f(a), f(b)};
	return {3, 3};
}

ll ds(ll x, ll y) {
	return abs(x) + abs(y);
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	
	init();
	
	cin >> n >> x >> y;
	int u, v;
	string s;
	rep(k, 0, n) {
		cin >> s >> u >> v;
		pii p = deal(u, v);
		if(p.fi > 2) continue;
		ll z;
		if(dis[p.fi][p.se] > (z = ds(1LL*x-u, 1LL*y-v)))
			dis[p.fi][p.se] = z, c[p.fi][p.se] = s[0];
	}
	bool flag = 0;
	rep(i, 0, 3) rep(j, 0, 3) {
		if((i == 1 || j == 1) && (c[i][j] == 'R' || c[i][j] == 'Q')) flag = 1;
		if((i != 1 && j != 1) && (c[i][j] == 'B' || c[i][j] == 'Q')) flag = 1;
	}
	puts((flag) ? "YES" : "NO");
	return 0;
}
