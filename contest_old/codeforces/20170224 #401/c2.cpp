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

vector<vector<int > > v;
int n, m;
int ans[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	rep(i, 0, n) {
		vector<int > vz;
		int x;
		rep(j, 0, m) {
			cin >> x;
			vz.pb(x);
		}
		v.pb(vz);
	}
	rep(i, 0, n) ans[i] = i;
	rep(j, 0, m) {
		int l = 0, r = 0;
		rep(i, 1, n){
			if(v[i][j] >= v[i-1][j]) r++;
			else {
				ans[l] = max(r, ans[l]);
				l = r = i;
			}
		}
		ans[l] = r;
	}
	int z = 0;
	rep(i, 0, n) {
		if(ans[i] < z) ans[i] = z;
		else z = ans[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		if(ans[l] >= r) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
