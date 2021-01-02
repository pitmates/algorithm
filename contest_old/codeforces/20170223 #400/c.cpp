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

map<ll, int > m;
vector<ll > v;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, k;
	cin >> n >> k;
	ll s = 0, t = 0;
	
	if(abs(k) == 1) {
		v.pb(1);
		if(k == -1) v.pb(-1);
	}
	else {
		for(ll x = 1; x < 1e15; x *= k) v.pb(x);
	}

	m[0]++;
	rep(i, 0, n) {
		cin >> a;
		s += a;
		m[s]++;

		for(auto& u : v) if(m.count(s-u) != 0){
			t += m[s-u];
		}
	}
	cout << t << endl;
	return 0;
}
