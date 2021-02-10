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
const int N = 200100;

int m;
int a[N];
pii b[N], ans[N];

bool cmp(pii u, pii v) {
	return u.se < v.se;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m;
	rep(i, 0, m) cin >> a[i];
	int x;
	rep(i, 0, m) {
		cin >> x;
		b[i] = {x, i};
	}
	sort(b, b+m);
	sort(a, a+m);
	reverse(a, a+m);
	rep(i, 0, m) {
		ans[i] = {a[i], b[i].se};
	}
	sort(ans, ans + m, cmp);
	rep(i, 0, m) cout << ans[i].fi << " ";

	
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
