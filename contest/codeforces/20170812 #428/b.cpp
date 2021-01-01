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
const int N = 103;

int a[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int s = 0;
	rep(i, 0, k) {
		cin >> a[i];
		s += a[i] / 4;
		a[i] %= 4;
		if(a[i] == 3) a[i] = 0, ++s;
	}
	int on = 0, tw = 0;
	rep(i, 0, k) if(a[i]) {
		if(a[i] == 1) ++on;
		else ++tw;
	}
	int x = min(tw, on), all = n * 4;
	if(x <= n) {
		all -= 2 * x;
		tw -= x;
		on -= x;
		all -= on;
		if(tw <= n+n) all -= tw;
		else {
			all -= 2 * n;
			tw -= 2 *n;
			all -= (tw*2+2)/3 * 2;
			
		}
	}
	else {
		all -= 2 * x;
		tw -= x;
		on -= x;
		all -= on;
		all -= tw;
	}
	all -= s + s;
	// printf("s: %d  ss: %d\n", s, ss);
	if(all < 0) cout << "NO" << endl;
	else cout << "YES" << endl;


	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
