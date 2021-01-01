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
const int N = 3e5+7;

struct Coupon{
	int l, r;
	int id;
	Coupon(int l=0, int r=0, int i=0):l(l), r(r), id(i) {}
	bool operator < (const Coupon& a) const {
		return l < a.l;
	}
};

vector<Coupon > cou;
int n, k;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, y;
	cin >> n >> k;
	rep(i, 0, n) {
		cin >> x >> y;
		cou.pb({x, y, i+1});
	}
	sort(cou.begin(), cou.end());
	set<pii > cp;
	cp.clear();
	int here = 0, ans = 0;
	for(auto& u : cou) {
		cp.insert({u.r, u.id});
		while(sz(cp) > k) cp.erase(cp.begin());
		if(sz(cp) == k) {
			x = (*cp.begin()).fi - u.l + 1;
			if(x > ans) {
				ans = x;
				here = u.id;
			}
		}
	}
	cout << ans << endl;
	if(ans == 0) {
		rep(i, 1, k+1) cout << i << " ";
		cout << endl;
		return 0;
	}
	cp.clear();
	for(auto& u : cou) {
		cp.insert({u.r, u.id});
		while(sz(cp) > k) cp.erase(cp.begin());
		if(sz(cp) == k && u.id == here) break; 
	}
	for(auto& v : cp) cout << v.se << " ";
	cout << endl;
	return 0;
}
