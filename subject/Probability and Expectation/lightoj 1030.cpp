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
const int N = 110;
int n;
int x[N];
double dp[N];


int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	//ios_base::sync_with_stdio(false); cin.tie(0);

	int T, ic = 1;
	for(scanf("%d", &T); T--; ic++){
		scanf("%d", &n);
		rep(i, 1, n+1) {
			scanf("%d", x+i);
			dp[i] = 0.0;
		}
		dp[n] = x[n];
		for(int i = 1; (n-i) > 0 && i < 6; ++i){
			dp[n-i] = x[n-i];
			for(int j = n-i+1; j <= n; ++j)
				dp[n-i] += 1. / i * dp[j];
			//printf("i = %d  dp[%d] = %.3f\n", i, n-i, dp[n-i]);
		}
		for(int i = n-6; i > 0 ; --i) {
			dp[i] = x[i];
			for(int j = 1; j <= 6; ++j)
				dp[i] += 1. / 6 * dp[i+j];
		}
		printf("Case %d: %.8f\n", ic, dp[1]);
	}
	return 0;
}
