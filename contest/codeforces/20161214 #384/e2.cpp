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
const int N = 1003;
const int M = (1<<8);

int dp[N][M];
int n;
int g[N], cur[8];
vector<int > v[8];

int ok(int m) {
	zero(cur);
	zerox(dp, -1);
	dp[0][0] = 0;
	rep(i, 0, n) {
		rep(j, 0, M) if(dp[i][j] != -1){
			rep(k, 0, 8) if(!((1<<k)&j)){
				int x = m + cur[k] - 1, y, z;
				if(x >= sz(v[k])) continue;
				y = v[k][x]; z = j|(1<<k);
				dp[y][z] = max(dp[y][z], dp[i][j]);
				if(++x >= sz(v[k])) continue;
				y = v[k][x];
				dp[y][z] = max(dp[y][z], dp[i][j]+1);
			}
		}
		++cur[g[i]];
	}
	int x = -1;
	rep(i, 0, n) x = max(x, dp[i][M-1]);
	return x == -1 ? x : m*8+x;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 0, n) {
		cin >> g[i];
		v[--g[i]].pb(i);
	}
	int l = 1, r = (n>>3)+1, m;
	int res = 0, x;
	while(l + 1 <= r) {
		m = (l + r) >> 1;
		if((x = ok(m)) != -1) {
			l = m+1;
			res = max(res, x);
		}
		else r = m;
	}
	if(res == 0) rep(i, 0, 8) if(!v[i].empty()) ++res;
	cout << res;
	return 0;
}
