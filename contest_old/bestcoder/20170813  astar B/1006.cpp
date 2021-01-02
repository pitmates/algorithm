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
const int N = 100100;

int n, m;
struct P {
	ll l, r;
	P(ll _=0, ll __=0): l(_), r(__) {}
	bool operator<(const P& a) const {
		return l < a.l || (l == a.l && r < a.r);
	}
};
P p[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m) {
		ll l, r;
		rep(i, 0, n) {
			cin >> l >> r;
			p[i] = {l, r+1};
		}
		sort(p, p+n);
		int t = 0;
		rep(i, 1, n) {
			if(p[i].l <= p[t].r) p[t].r = max(p[t].r, p[i].r);
			else p[++t] = p[i];
		}
		n = ++t;
// printf("n == %d\n", n);
// rep(i, 0, n) printf("i:%d  [%I64d %I64d) \n", i, p[i].l, p[i].r);
		ll s = 0, ans = 0, mx = 0;
		int f = 0;
		rep(i, 0, n) {
			ans += p[i].r - p[i].l;
			ll d = (i < n-1) ? p[i+1].l - p[i].r : 0LL;
			s += d;
			ans += d;
			if(s > m) {
				mx = max(mx, ans + m-s);
				while(s > m) {
					int dd = p[f+1].l - p[f].r;
					s -= dd;
					ans -= p[f].r - p[f].l;
					ans -= dd;
					++f;
				}
			}
		}
		mx = max(mx, ans + m-s);
		cout << mx << endl;
	}


	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
