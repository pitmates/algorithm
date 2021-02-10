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

		int n, g, m;
		cin >> n >> g >> m;

		vector<pii > loc;
		map<pii, int > counter; counter.clear();

		for (int i = 1; i <= g; ++i) {
		    int c; char d;
		    cin >> c >> d; --c;

		    int z, y;
		    if (d == 'C') { z = (c + m) % n; y = -1; }
		    else { z = ((c - m) % n + n) % n; y = 1; }

            if (counter[{z, y}] == 0) { loc.push_back({z, y}); }
            counter[{z, y}]++;
		}

		sort(loc.begin(), loc.end());

		int st = 0;
		for (st = 0; st < loc.size())
		for (int i = 0; i < loc.size(); ++i) {

		}

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}