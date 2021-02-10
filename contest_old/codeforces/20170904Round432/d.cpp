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
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 2000100;

int n, x, y;
int c[N];
ll s[N];
bool pr[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x >> y;
	int a;
	zero(c);
	zero(s);
	zero(pr);
	rep(i, 0, n) {
		cin >> a;
		c[a]++;
		s[a] += a;
	}
	rep(i, 1, N) c[i] += c[i-1], s[i] += s[i-1];
	ll ans = INF;
	rep(i, 2, N) if(!pr[i]) {
		for(int j = i+i; j < N; j += i) pr[j] = 1;
		ll res = 0;
		int z = min(i, x/y+1);
		for (int j = i; j < N; j += i) {
			res += (1LL*(c[j]-c[j-z])*j - 1LL*(s[j]-s[j-z])) * y;
			res += 1LL*(c[j-z] - c[j-i]) * x;
		}
		ans = min(ans, res);
	}
	cout << ans;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
