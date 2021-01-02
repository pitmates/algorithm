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

int n, k;
int t[N];
vector<int > v;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int s = 0;
	rep(i, 1, n+1) {
		cin >> t[i];
		if(t[i] < 0) ++s;
	}
	if(s == 0) {
		cout << 0;
		return 0;
	}
	if(s > k){
		cout << -1;
		return 0;
	}
	int f = 0, i, x = 0; 
	for(i = 1; i <= n; ++i) if(t[i] < 0) break;
	for( ; i <= n; ++i){
		if(!f && t[i] >= 0 && t[i-1] < 0) f = 1, x = 0;
		if(f && t[i] >= 0) ++x;
		if(f && t[i] < 0) {
			v.pb(x); f = 0; x = 0;
		}
	}
	sort(v.begin(), v.end());
	f = 0;
	for(int i = 0; i < sz(v); ++i) {
		if(s + v[i] <= k) s += v[i];
		else ++f;
	}
	int ans = 1 + f + f;
	if(s + x > k) ++ans;
	cout << ans ;
	return 0;
}
