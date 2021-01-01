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
const int N = 7007;

int n;
int k[2];
int s[2][N];
int dp[2][N];
int win[2][N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cin >> k[0]; rep(i, 0, k[0]) cin >> s[0][i];
	cin >> k[1]; rep(i, 0, k[1]) cin >> s[1][i];
	zerox(dp, -1);
	rep(z, 0, 2) rep(i, 0, n) win[z][i] = k[z];
	queue<pii > Q;
	while(!Q.empty()) Q.pop();
	Q.push({0, 0});
	Q.push({1, 0});
	dp[0][0] = dp[1][0] = 0;
	while(!Q.empty()) {
		int u = Q.front().fi, v = Q.front().se; Q.pop();
//printf("u:%d  v:%d  dp[u][v]:%d\n", u, v, dp[u][v]);
		int x = u^1, y;
		if(dp[u][v] == 0) {
			rep(i, 0, k[x]) {
				y = (v - s[x][i] + n) % n;
				if(dp[x][y] == -1) {
					dp[x][y] = 1;
					Q.push({x, y});
				}
			}
		}
		else {
			rep(i, 0, k[x]) {
				y = (v - s[x][i] + n) % n;
				--win[x][y];
				if(dp[x][y] == -1 && win[x][y] == 0) {
					dp[x][y] = 0;
					Q.push({x, y});
				}
			}
		}
	}
	rep(z, 0, 2) {
		rep(i, 1, n) {
			if(dp[z][i] == 1) cout << "Win ";
			else if(!dp[z][i]) cout << "Lose ";
			else cout << "Loop ";
		}
		cout << endl; 
	}
	return 0;
}
