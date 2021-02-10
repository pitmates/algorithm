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

bool vis[22][22];
int flag;
int R, C;
pii trace[500];


bool isvalid(int rr, int cc, int r, int c) {
    if (rr == r) return false;
    if (cc == c) return false;
    if (rr + c == cc + r) return false;
    if (rr + cc == r + c) return false;
    if (vis[rr][cc]) return false;
    return true;
}

void dfs(int r, int c, int cnt) {
    if (flag == 1) return ;
    trace[cnt] = {r, c};
    vis[r][c] = 1;
    if (cnt == R*C) {
        flag = 1;
        return ;
    }

    for (int rr = 1; rr <= R; ++rr) {
        for (int cc = 1; cc <= C; ++cc) {
            if (!isvalid(rr, cc, r, c)) continue;
            dfs(rr, cc, cnt+1);
        }
    }
    vis[r][c] = 0;
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
		cin >> R >> C;
		zero(vis);
		for (int i = 0; i < 500; ++i) trace[i] = {0, 0};
		flag = 0;
		for (int r = 1; r <= R; ++r) {
		    for (int c = 1; c <= C; ++c) {
		        dfs(r, c, 1);
		    }
		}
		//dfs(1, 1, 1);
		if (flag == 0) cout << "IMPOSSIBLE" << endl;
		else {
		    cout << "POSSIBLE" << endl;
		    for (int i = 1; i <= R*C; ++i) {
		        cout << trace[i].fi << " " << trace[i].se << endl;
		    }
		}

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*

1
3 20
3 4
2 5


*/
