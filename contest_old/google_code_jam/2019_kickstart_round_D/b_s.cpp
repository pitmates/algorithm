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

vector<pii > trace[123];


void update(int t, int pos, int id) {
    if (trace[pos].empty()) {
        trace[pos].push_back({t, id});
    }
    else {
        if (trace[pos][0].fi < t) {
            trace[pos].clear();
            trace[pos].push_back({t, id});
        }
        else if (trace[pos][0].fi == t) {
            trace[pos].push_back({t, id});
        }
    }
    return;
}



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
		int n, g, m; cin >> n >> g >> m;

		for (int i = 0; i < 123; ++i) trace[i].clear();

		for (int ig = 0; ig < g; ++ig) {
		    int cir;
		    char c;
		    cin >> cir >> c;
		    --cir;
		    int u = min(m, n), pos = cir;
		    if (c == 'C') {
		        update(0, pos, ig);
		        for (int i = 1; i <= m; ++i) {
		            pos = (pos + 1) % n;
		            int v = pos;
		            update(i, v, ig);
		        }
		    }
		    else {
		        update(0, pos, ig);
                for (int i = 1; i <= m; ++i) {
                    pos = (pos - 1 + n) % n;
                    int v = pos;
                    update(i, v, ig);
                }
		    }
		}

		vector<int > rem(g, 0);
		for (auto z : trace) {
		    for (auto w : z) {
//		        cout << w.fi << " " << w.se << endl;
		        int guest = w.se;
		        rem[guest]++;
		    }
		}
		for (int i = 0; i < g; ++i) cout << rem[i] << " ";
		cout << endl;

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}