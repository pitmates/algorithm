//
// coded by lp.z
//

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


int dp[56][34][1567];


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
		zero(dp);

		int n, K, P;
		cin >> n >> K >> P;

		vector<vector<int > > B(n, vector<int > (K+1, 0));
		for (int i = 0; i < n; ++i) {
		    for (int j = 1; j <= K; ++j) {
                cin >> B[i][j];
                B[i][j] += B[i][j-1];
		    }
		}


		for (int j = 0; j <= K && j <= P; ++j) dp[0][j][j] = B[0][j];

//        for (int j = 0; j <= K && j <= P; ++j) cout << dp[0][j][j] << " "; cout << endl;

		for (int i = 1; i < n; ++i) for (int j = 0; j <= K; ++j) {
		    for (int k = j; k <= P ; ++k)
		        for (int l = 0; l <= K && l+j <= k; ++l)
		        dp[i][j][k] = max(dp[i - 1][l][k - j] + B[i][j], dp[i][j][k]);
		}


		int mx = 0;
		for (int j = 0; j <= K; ++j) {
		    mx = max(mx, dp[n-1][j][P]);
		}
		cout << mx << endl;


    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}