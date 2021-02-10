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
		
		int n, k;
		cin >> n >> k;
		vector<int > c(n, 0), d(n, 0);
		for (int i = 0; i < n; ++i) cin >> c[i];
		for (int i = 0; i < n; ++i) cin >> d[i];
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
		    for (int j = i; j < n; ++j) {
		        int mc = 0, md = 0;
		        for (int x = i; x <= j; ++x) {
		            mc = max(mc, c[x]);
		            md = max(md, d[x]);
		        }
		        if (abs(mc - md) <= k) ++cnt;
		    }
		}
		cout << cnt << endl;
    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}