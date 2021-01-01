#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

map<string, vector<ll > > mp;
int n, k;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	ll x;
	cin >> k >> n;
	rep(i, 0, k) {
		cin >> s >> x;
		mp[s].pb(x);
	}
	ll ans = 0, res = 0, mid = 0;
	for(auto& p : mp) {
		auto& s = p.fi;
		auto& v = p.se;
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		auto r = s;
		reverse(r.begin(), r.end());
		if(r == s) {
			int i = 0;
			for( ; i < sz(v)-1; i += 2) {
				if(v[i] + v[i+1] < 0) break;
				ans += v[i] + v[i+1];
				mid = max(mid, -v[i+1]);
			}
			for( ; i < sz(v); ++i) mid = max(mid, v[i]);
		}
		else {
			if(mp[r].empty()) continue;
			auto& vr = mp[r];
			sort(vr.begin(), vr.end());
			reverse(vr.begin(), vr.end());
			int x = min(sz(vr), sz(v));
			for(int i = 0; i < x; ++i) {
				if(v[i] + vr[i] <= 0) break;
				res += v[i] + vr[i];
			}
		}
	}
	cout << (ans + mid + res / 2) << endl;
	return 0;
}
