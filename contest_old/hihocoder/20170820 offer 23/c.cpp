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
const ll mo = (ll)1e9+7;

struct Matrix{
	ll m[10][10];
	int cr;

	void init(int x) {
		cr = x;
		rep(i, 0, cr) rep(j, 0, cr) m[i][j] = 0;
	}
	void it(int x) {
		// cr = x;
		init(x);
		rep(i, 0, x) m[i][i] = 1;
	}

	Matrix multiply(Matrix a) {
		Matrix tp;
		tp.init(a.cr);
		rep(k, 0, cr) rep(i, 0, cr) rep(j, 0, cr) {
			(tp.m[i][j] += m[i][k] * a.m[k][j] % mo) %= mo;
		}
		return tp;
	}

	// void out() {
	// 	rep(i, 0, cr) {
	// 		rep(j, 0, cr) printf("%lld ", m[i][j]); puts("");
	// 	}
	// }

};

Matrix qmod(Matrix a, ll x) {
	Matrix tp;
	tp.it(a.cr);
	while(x) {
		if(x&1) tp = tp.multiply(a);
		a = a.multiply(a);
		x >>= 1;
	}
	return tp;
}

ll n;
int k;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	Matrix z, fs;
	z.init(10);
	fs.init(10);
	rep(i, 0, 10) rep(j, 0, 10) {
		if(i <= k && i*j <= k) z.m[i][j] = 1;
	}
	rep(i, 0, 10) fs.m[0][i] = 1;
	// --n;
	Matrix ans = qmod(z, n);
	ans.multiply(fs);
	ll res = 0;
	// ans.out();
	rep(i, 1, 10) res += ans.m[i][0];
	cout << res % mo << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
