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


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T, W;
    for(cin >> T >> W; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;

		vector<ll > ans(10, 0LL);

		int Q = 215;
		cout << Q << endl;
		ll r;
		cin >> r;
		ans[4] = r >> 53;
		ans[5] = (r % (1LL << 53)) >> 43;
		ans[6] = (r % (1LL << 43)) >> 35;

		cout.flush();

		Q = 53;
		cin >> r;
		ans[1] = r >> 53;

		r -= (ans[4] << 13);
		r -= (ans[5] << 10);
		r -= (ans[6] << 8);

		ans[2] = (r % (1LL << 53)) >> 26;
		ans[3] = (r % (1LL << 26)) >> 17;

		for (int i = 1; i < 7; ++i) cout << ans[i] << " ";
		cout << endl;
		cout.flush();
		cin >> r;

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}