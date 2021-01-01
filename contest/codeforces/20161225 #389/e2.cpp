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
const int N = 1e7+1;

int g[N], m[N];
int n, k;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int x;
	zero(g); zero(m);
	rep(i, 0, n) cin >> x, ++g[x];
	ll ans = 0;
	for(int i = N-1; i; --i) {
		ans += g[i];
		if(ans >= k) {
			cout << i ;
			return 0;
		}
		g[i>>1] += g[i] + m[i];
		m[i-(i>>1)] += g[i] + m[i];
	}
	cout << -1;
	return 0;
}
