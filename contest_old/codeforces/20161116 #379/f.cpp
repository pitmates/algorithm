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
const int N = 200200;

int n;
ll b[N], c[N];
ll a[N];
int dg[32];

void solve() {
	zero(dg);
	ll sum = 0, suma = 0;
	rep(i, 0, n) sum += b[i] + c[i];
	suma = sum / (n+n);
	bool flag = 1;
	rep(i, 0, n) {
		a[i] = (b[i] + c[i] - suma) / n;
		if(a[i] < 0) flag = 0;
	}
	if(!flag) { cout << "-1"; return; }
	rep(i, 0, n) {
		int t = 0;
		for(ll x = a[i]; x; x >>= 1) dg[t++] += (x&1);
	}	 
	rep(i, 0, n) {
		ll x = a[i], sumi = 0;
		rep(j, 0, 32) if((x>>j)&1) sumi += (1<<j)*dg[j];
		if(sumi != b[i]) { flag = 0; break; }
	}
	if(!flag) {cout << "-1"; return;}
	rep(i, 0, n) {
		ll x = a[i], sumi = 0;
		rep(j, 0, 32) {
			if((x>>j)&1) sumi += (1<<j)*n;
			else sumi += (1<<j)*dg[j];
		}
		if(sumi != c[i]) { flag = 0; break; }
	}
	if(!flag) {cout << "-1"; return;}
	rep(i, 0, n) cout << a[i] << " ";

}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, 0, n) cin >> b[i];
	rep(i, 0, n) cin >> c[i];
	solve();
	return 0;
}
