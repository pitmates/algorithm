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
#define db double

using namespace std;
const db pi = acos(-1.0);
const int N = 200017;

pii u, v;
pii p[N];
int n;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	//ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d %d %d", &u.fi, &u.se, &v.fi, &v.se);
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d %d", &p[i].fi, &p[i].se);
	sort(p, p+n);
	if(u.fi > v.fi) swap(u, v);
	if(u.se > v.se) reverse(p, p+n);
	vector<int > vp; vp.clear();
	
	int mi = min(u.se, v.se), mx = max(u.se, v.se);
//printf("st:%d  ed:%d  mi:%d  mx:%d\n", st, ed, mi, mx);
	for(int i = 0; i < n; ++i) {
		if(p[i].se > mx || p[i].se < mi) continue;
		if(p[i].fi > v.fi || p[i].fi < u.fi) continue;
		// printf("i == %d\n", i);
		if(vp.empty() || p[i].se > vp.back()) vp.pb(p[i].se);
		else {
			int d = upper_bound(vp.begin(), vp.end(), p[i].se) - vp.begin();
			vp[d] = p[i].se;
		}
	}
	db ans = 100.0*(v.fi-u.fi + mx-mi);
	int m = sz(vp);
	ans -= 20.0*m;
	ans += pi*5*m;
	if(m == min(mx-mi+1, v.fi-u.fi+1)) ans += pi*5;
	printf("%.15f\n", ans);
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
