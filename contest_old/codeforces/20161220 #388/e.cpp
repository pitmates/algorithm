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
#define lowbit(x) ((x)&(-x))

using namespace std;
const int N = 100003;

int p[N];
int n;
double ans;
ll b[N];

void upd(int x, int p) {
	for( ; x <= n; x += lowbit(x)) b[x] += p;
}
ll sum(int x) {
	ll ans = 0;
	for( ; x; x -= lowbit(x)) ans += b[x];
	return ans;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
 	ans = 0.0;
	rep(i, 1, n+1) cin >> p[i];
	for(int i = n; i; --i) {
		ans += sum(p[i]);
		upd(p[i], 1);
	}
	double t = 0.0;
	rep(i, 1, n+1) b[i] = 0;
	for(int i = n; i; --i) {
		t += 1. * sum(p[i]) * i;
		upd(p[i], n-i+1);
	}
	ans -= t / n / (n+1) * 2. ;
	for(int i = 1; i <= n; ++i) 
		ans += .5 * i / n * (i-1) / (n+1) * (n-i+1);
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}
