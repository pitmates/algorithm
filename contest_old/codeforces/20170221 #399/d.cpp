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
const int N = 7315;
const int M = 1010;

double dp[N][M];
int k, q;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k >> q;
	rep(i, 0, N) rep(j, 0, M) dp[i][j] = 0.;
	dp[0][0] = 1.;
	rep(i, 1, N) for(int j = 1; j <= i && j < M; ++j) {
		dp[i][j] = (dp[i-1][j] * j + dp[i-1][j-1] * (k-j+1)) / k;
	}
	while(q--) {
		int p, i;
		cin >> p;
		for(i = k; i < N; ++i) if(dp[i][k] >= 1.*p/2000) break;
		cout << i << endl;
	}
	return 0;
}
