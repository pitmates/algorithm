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
const int N = 200200;

pii p[N];
int n;

bool cmp(pii a, pii b) {
	return (a.fi < b.fi) || (a.fi == b.fi && a.se < b.se);
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int l, r;
	rep(i, 0, n) {
		cin >> l >> r;
		p[i] = {l, r};
	}
	if(n < 3) cout << "YES" ;
	else {
		sort(p, p+n, cmp);
		int fir = p[0].se, sec = p[1].se;
		if(fir > sec) swap(fir, sec);
		int f = 1;
		rep(i, 2, n) {
			if(p[i].fi <= fir) {f = 0; break; }
			fir = p[i].se;
			if(fir > sec) swap(fir, sec);
		}
		if(f) cout << "YES";
		else cout << "NO";
	}
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}