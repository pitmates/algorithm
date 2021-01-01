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
const int N = 1010;

int n, m;
double P[N];
double dp[N][N];


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> P[i];
	rep(i, 0, n+1) rep(j, 0, n+1) dp[i][j] = 0.0;
	dp[0][0] = 1;
	rep(i, 1, 1+n) dp[i][0] = dp[i-1][0] * (1-P[i]);
	rep(i, 1, 1+n) rep(j, 1, 1+m) {
		dp[i][j] = dp[i-1][j] * (1-P[i]) + dp[i-1][j-1] * P[i];
	}
	cout.precision(8);
	cout << dp[n][m] << endl;
	return 0;
}
