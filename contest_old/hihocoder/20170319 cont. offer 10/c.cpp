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

int a[N];
map<int, int > mmp;
int n;
ll k;

int s[N];
bool check(ll x) {
	zero(s);
	ll ans = 0, res = 0;
	int q = 0;
	rep(i, 0, n) {
		ans += s[a[i]]++;
		while(ans > x) ans -= --s[a[q++]];
		res += i-q+1;
	}
//printf("x: %I64d  ans: %I64d  res: %I64d\n", x, ans, res);
	return res >= k;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		mmp.clear();
		int tot = 0;
		rep(i, 0, n) {
			cin >> a[i];
			if(mmp.find(a[i]) == mmp.end()) mmp[a[i]] = tot++;	
			a[i] = mmp[a[i]];
		}
		ll l = 0, r = 1LL*n*(n+1)/2, mid;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(check(mid)) r = mid-1;
			else l = mid+1;
		}
		//printf("%I64d %I64d %I64d\n", l, r, mid);
		cout << l << endl;
	}
	return 0;
}
