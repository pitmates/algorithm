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
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 100103;

int n;
pii p[N];
vector<pii > E[N];
vector<int > x;

bool cmp(pii x, pii y) {
	return x.se < y.se;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int a, b;
	int f = -1, z = 0, one = 0;
	rep(i, 1, 1+n) {
		cin >> a >> b;
		p[i] = {a, b};
		if(a == 1) ++one;
		if(b == 1) x.pb(i);
		else {
			if(sz(E[b]) > 0) {
				if(E[b][0].first == 1) {
					f = 0;
					z = b;
					x.pb(i);
				}
				else if(a == 1) {
					x.pb(E[b][0].se) ;
					z = b;
					f = 1;
				}
				else x.pb(i), x.pb(E[b][0].se);
			}
			E[b].pb({a, i});
		}
	}

	if(f == 0) 	x.pb(E[z][0].se);
	else if(f == 1) x.pb(E[z][1].se);
	sort(x.begin(), x.end());
	cout << x[0];
	rep(i, 1, sz(x)) cout << " " << x[i];
	cout << endl;
	return 0;
}
