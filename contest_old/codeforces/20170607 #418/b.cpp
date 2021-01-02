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
const int N = 1010;

int a[N], b[N];
int fa[N], fb[N];
int n;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	zero(fa);
	zero(fb);
	int x, y;
	rep(i, 0, n) cin >> a[i], fa[a[i]]++;
	
	rep(i, 0, n) cin >> b[i], fb[b[i]]++;

	rep(i, 1, 1+n) {
		if(fa[i] == 2) x = i;
		if(fa[i] == 0) y = i;
	}
	int u = -1, v = -1;
	rep(i, 0, n) {
		if(a[i] != b[i] && u == -1) {
			u = i;
		}
		else if(a[i] != b[i]) v = i;
	}
	if(v == -1) {
		a[u] = y;
	}
	else {
		if(b[u] == y) a[u] = y;
		else a[v] = y;
	}
	rep(i, 0, n) cout << a[i] << " ";

	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
