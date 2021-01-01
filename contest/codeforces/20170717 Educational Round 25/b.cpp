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
const int N = 11;

string s[N];

int dx[] = {0, 1, 1, 1};
int dy[] = {1, -1, 0, 1};

bool in(int x, int y) {return max(x, y) < 10 && min(x, y) >= 0; }

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	
	rep(i, 0, 10) cin >> s[i];
	rep(i, 0, 10) rep(j, 0, 10) if(s[i][j] != 'O'){
		rep(k, 0, 4) {
			int x = i, y = j, u = 0, v = 0;
			for(int z = 0; z < 5 && in(x, y); ++z) {
				if(s[x][y] == 'X') ++u;
				else if(s[x][y] == '.') ++v;
				x += dx[k]; y += dy[k];
			}
			if(u == 4 && v == 1) {cout << "Yes";  return 0; }
		}
	}
	cout << "No";
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
