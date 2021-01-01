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
int n, x;
int a[N], b[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> x;
	zero(b);
	rep(i, 0, n) cin >> a[i], b[a[i]]++;
	ll ans = 0;
	rep(i, 0, n){
		int y = x ^ a[i];
		if(y >= N || !b[a[i]] || !b[y]) continue;
		if(y == a[i]) ans += 1LL * b[y] * (b[y]-1) / 2;
		else ans += 1LL * b[y] * b[a[i]];
		b[y] = b[a[i]] = 0;
	}
	cout << ans;
	return 0;
}
