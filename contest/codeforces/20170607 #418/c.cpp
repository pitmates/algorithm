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

int n, q;
vector<int > wd[26];
vector<int > bk[26];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	string s;
	cin >> s;
	cin >> q;
	rep(i, 0, 26) wd[i].clear();
	rep(i, 0, n) {
		wd[s[i]-'a'].pb(i);
	}
	while(q--) {
		int m;
		string c;
		cin >> m >> c;
		if(m + sz(wd[c[0]-'a']) >= n) cout << n << endl;
		else {
			int k = 0, w = c[0] - 'a', z = sz(wd[w]);
			if(z < 2) {
				cout << m + z << endl;
				continue;
			}
			int l = 0, mx = 0;
			rep(i, 0, z-1) {
				int x = k + wd[w][i+1] - wd[w][i] - 1;
				if(x > m) {

					int le = wd[w][i] - wd[w][l] + 1 + m - k;
					mx = max(mx, le);
					while(x > m) {
						//printf("m:%d x:%d ", m, x);
						int sub = wd[w][l+1] - wd[w][l] - 1;
						x -= sub;
						++l;
						//printf("l: %d\n", l);
					}
				}
				k = x;
			}
			//printf("%d %d %d %d %d\n", mx, z, l, m, k);
			mx = max(mx, wd[w].back()-wd[w][l]+1+m-k);
			cout << mx << endl;

		}
	}

	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
