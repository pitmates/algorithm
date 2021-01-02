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
typedef pair<pii, ll > pi3;
const int N = 100100;

int n;
pi3 p[N];
ll ans[N];

inline bool cmp(pi3 a, pi3 b) {
	if(a.fi.se == b.fi.se) return a.fi.fi < b.fi.fi;
	return a.fi.se > b.fi.se;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int in, ou, he;
	rep(i, 0, n) {
		cin >> in >> ou >> he;
		p[i] = {{in, ou}, 1LL*he};
	}
	sort(p, p+n, cmp);
	int t = 0;
	rep(i, 1, n) {
		if(p[i].fi.se == p[t].fi.se) p[t].se += p[i].se;
		else p[++t] = p[i];
	}
	n = ++t;
	stack<int > sk;
	while(!sk.empty()) sk.pop();
	zero(ans);
	rep(i, 0, n) {
		while(!sk.empty() && p[sk.top()].fi.fi >= p[i].fi.se)
			sk.pop();
		ans[i] += p[i].se;
		if(!sk.empty()) ans[i] += ans[sk.top()];
		sk.push(i);
	}
	cout << *max_element(ans, ans+n) << endl;
	return 0;
}
