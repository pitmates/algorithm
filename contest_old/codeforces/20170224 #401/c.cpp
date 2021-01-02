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
const int N = 100100;

vector<vector<int > > table;

int n, m;

map<pii, int > mmp;
pii p[N];
int t = 0;

bool cmp(pii a, pii b) {
	if(a.fi == b.fi) return a.se > b.se;
	return a.fi < b.fi;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	table.clear();
	for(int i = 0; i < n; ++i) {
		int x;
		vector<int > tp;
		tp.clear();
		for(int j = 0; j < m; ++j) {
			cin >> x;
			tp.pb(x);
		}
		table.pb(tp);
	}

	for(int j = 0; j < m; ++j) {
		int l = 0, r = 0;
		for(int i = 1; i < n; ++i) {
			if(table[i][j] >= table[i-1][j]) ++r;
			else {
				p[t++] = {l, r};
				l = r = i;
			}
		}
		p[t++] = {l, r};
	}
	sort(p, p+t, cmp);

	int x = 0;
	for(int i = 1; i < t; ++i) {
		if(p[x].fi == p[i].fi) continue;
		if(p[x].se >= p[i].se) continue;
		p[++x] = p[i];
	}
	t = x+1;

	int k, l, r;
	cin >> k;
	while(k--) {
		cin >> l >> r;
		--l, --r;
		int id = lower_bound(p, p+t, mp(l, r)) - p;
		if(p[id].fi == l) {
			if(p[id].se >= r) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else {
			if(p[id-1].se >= r) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}
