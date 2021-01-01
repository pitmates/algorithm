#include <bits/stdc++.h>

#ifdef PIT
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 100100;
const double eps = 1e-6;

int n, p;
pii device[N];

inline int sig(double x) {return (x>eps) - (x<-eps);}

bool calc(double x) {
	double s = 0;
	rep(i, 0, n) {
		s += max(0., device[i].fi * x - device[i].se);
	}
	return sig(p*x - s) >= 0;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
int _time_zlp = clock();
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> p;
	ll s = 0;
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		s += a;
		device[i] = {a, b};
	}
	if(s <= p) {
		cout << -1 << endl;
		return 0;
	}
	double l = 0., r = 1e15, m;
	rep(i, 0, 150) {
		m = (l + r) * 0.5;
		if(calc(m)) l = m;
		else r = m;
	}
	cout.precision(6);
	cout << l << endl;
	
#ifdef PIT
debug("Time: %f s\n", double(clock()-_time_zlp)/CLOCKS_PER_SEC);
#endif //PIT
	return 0;
}
