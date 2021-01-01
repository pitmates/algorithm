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

vector<int > lo[8];
int dp[N][M];
int cur[8];
int a[N], n;

int check(int m) {
	rep(i, 0, 8) cur[i] = 0;
	rep(i, 0, n) rep(j, 0, M) dp[i][j] = -1;
	dp[0][0] = 0;
	rep(i, 0, n) {
		rep(j, 0, M) if(dp[i][j] != -1){
			rep(k, 0, 8) if(!(j & (1<<k))) {
				int p = m + cur[k] - 1;
				if(p >= sz(lo[k])) continue;
				dp[lo[k][p]][j|(1<<k)] = max(dp[lo[k][p]][j|(1<<k)], dp[i][j]);
				if(++p >= sz(lo[k])) continue;
				dp[lo[k][p]][j|(1<<k)] = max(dp[lo[k][p]][j|(1<<k)], dp[i][j]+1);
			}
		}
		++cur[a[i]];
	}
	int res = -1;
	rep(i, 0, n) res = max(dp[i][M-1], res);
	return res == -1 ? res : (res + 8 * m);
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 0, 8) lo[i].clear();
	rep(i, 0, n) {
		cin >> a[i];
		lo[--a[i]].pb(i);
	}

	int l = 1, r = (n >> 3)+1, mid;
	int res = 0, s;
	while(l + 1 <= r) {
		mid = (l + r) >> 1;
		if((s = check(mid)) != -1) {
			l = mid + 1;
			res = max(res, s);
		}
		else r = mid ;
	}
//cout << "res = " << res << endl;
	if(res == 0) rep(i, 0, 8) if(!lo[i].empty()) ++res;
	cout << res ;
	return 0;
}
