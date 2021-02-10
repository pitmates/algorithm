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
		int k, n; cin >> k >> n;
		vector<pii > a(n);
		for (int i = 0; i < n; ++i) cin >> a[i].fi;
		for (int i = 0; i < n; ++i) cin >> a[i].se;

		ll res = INF;
		for (int i = 0; i < n; ++i) {
		    vector<int > val; val.clear();
		    for (int j = 0; j < n; ++j) {
		        if (j == i) continue;
		        int cost = a[j].se + abs(a[j].fi - a[i].fi);
		        val.push_back(cost);
		    }
		    sort(val.begin(), val.end());
		    ll cost = 0;
		    for (int c = 0; c < k; ++c) cost += val[c];
		    cost += a[i].se;
		    res = min(res, cost);
		}
		cout << res << endl;

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}