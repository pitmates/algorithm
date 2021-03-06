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

const int N = 110;
int n, m;
int a[N], pre[N];
int p[N<<1];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m; pre[0] = 0;
	rep(i, 1, n+1) cin >> a[i], pre[i] = pre[i-1] + a[i];
	int l, r;
	zero(p);
	rep(i, 0, m) {
		cin >> l >> r;
		if(pre[r] - pre[l-1] <= 0) continue;
		rep(j, l, r+1) p[a[j]+100]++;
	}
	int ans = 0;
	rep(i, 0, N<<1) if(p[i]) ans += (i-100)*p[i];
	cout << ans ;

	return 0;
}
