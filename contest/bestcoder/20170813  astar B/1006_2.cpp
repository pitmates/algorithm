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

int n;
ll m;
struct P {
	ll l, r;
	P(ll _=0, ll __=0): l(_), r(__) {}
	bool operator<(const P& a) const {
		return l < a.l || (l == a.l && r < a.r);
	}
};
P p[N];

ll dds[N];

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
		dds[0] = 0LL;
		rep(i, 1, n) dds[i] = dds[i-1] + p[i].l - p[i-1].r;
// printf("n == %d\n", n);
// rep(i, 0, n) printf("i:%d  [%d %d) \n", i, p[i].l, p[i].r);
		int lf = 0, rf = 0;
		ll ans = 0, mx = 0, s = 0;
		for( ; lf < n; ++lf) {
			
			if(rf < n){
				while(rf < n) {
					ll d = p[rf+1].l - p[rf].r;
					if(s + d > m) {
						mx = max(mx, ans+m-s);
						s = s - p[lf+1].l - p[lf].r;
						ans -= p[lf].r-p[lf].l;
						ans -= p[lf+1].l - p[lf].r;
						break;
					}
					else {
						s += d;
						ans += d + p[rf+1].r - p[rf+1].l;
						++rf;
					}
					if(rf == n) mx = max(mx, ans+m-s);
				}
			}
			else {
				mx = max(mx, p[n-1].r-p[lf].l+1+m-dds[n-1]+dds[lf]);
			}
		}
		cout << mx << endl;
	}


	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
