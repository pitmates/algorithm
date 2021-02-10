//
// Created by pitmates on 2019-04-29.
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

const int N = 555;

struct P{
    int x, y;
    string d;
};

P per[N];

int res[12][12];


int count(int u, int v, int p) {
    int ans = 0;
    for (int i = 0; i < p; ++i) {
        if (per[i].d == "N" && v > per[i].y) ++ans;
        else if (per[i].d == "S" && v < per[i].y) ++ans;
        else if (per[i].d == "E" && u > per[i].x) ++ans;
        else if (per[i].d == "W" && u < per[i].x) ++ans;
    }
    return ans;
}

int main()
{
#ifdef PIT
freopen("in.txt", "r", stdin);
freopen("as.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
		int p, q;
		cin >> p >> q;
		for (int i = 0; i < p; ++i) {
		    cin >> per[i].x >> per[i].y >> per[i].d;
		}

		zero(res);
		int u, v, mx = 0;
		for (int i = 0; i <= q; ++i) {
		    for (int j = 0; j <= q; ++j) {
		        res[i][j] = count(i, j, p);
		        if (res[i][j] > mx) {
		            mx = res[i][j];
		            u = i, v = j;
		        }
		    }
		}
		cout << u << " " << v << endl; // "  ++: " << mx << endl;

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}