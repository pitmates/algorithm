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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	ll q, h, s, d, n;
	cin >> q >> h >> s >> d;
	cin >> n;
	ll pri = q, y;
	if(pri*2 > h) pri = h;
	else pri = pri*2;
	if(pri*2 > s) pri = s;
	else pri = pri*2;
	y = pri;
	if(pri*2 > d) pri = d;
	else pri = pri*2;
	if(n&1) cout << n/2 * pri + y << endl;
	else cout << n/2 * pri << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
