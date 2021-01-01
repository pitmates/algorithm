#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>

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
const int mo = 1e9+7;
const int N = 303;

int dp[N<<1][N][N];
int n, K;

void upd(int &x, int y) {
	x += y;
	if(x >= mo) x -= mo;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> K;
	zero(dp);
	dp[0][0][0] = 1;
	rep(i, 0, n+n) {
		rep(j, 0, n+1) rep(k, 0, n+1) if(dp[i][j][k]){
			if(j < n && j < n) upd(dp[i+1][j+1][k+1], dp[i][j][k]);
			upd(dp[i+1][j][max(0, k-1)], dp[i][j][k]);
		}
	}
	cout << dp[n+n][n][K] << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
