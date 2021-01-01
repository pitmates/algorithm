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
const int N = 100100;

vector<int > one, two, three;
int tt[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	rep(i, 1, 1+n) {
		int x;
		cin >> x;
		if(x == 1) one.pb(i);
		else if(x == 2) two.pb(i);
		else three.pb(i);
	}
	ll ans = 0;
	int st = sz(three), sw = sz(two);
	int tx = 0;
	for(int i = 0; i < sw; ++i) {
		int x = lower_bound(three.begin(), three.end(), two[i]) - three.begin();
		tt[tx++] = st - x;
	}
	tt[tx] = 0;
	for(int i = tx-1; i >= 0; --i) tt[i] = tt[i+1] + tt[i];
	for(auto & u : one) {
		int y = lower_bound(two.begin(), two.end(), u) - two.begin();
		ans += tt[y];
	}
	cout << ans << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
