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
const int N = 2e5+7;

int a[N], b[N];
int n;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 1, 1+n) cin >> a[i];

	int i, t = 1;
	for(i = n; i > 0; i -= 2) b[t++] = a[i];
	i = (n&1) ? i+3 : i+1;
	for( ; i <= n; i += 2) b[t++] = a[i];
	cout << b[1];
	for(int i = 2; i <= n; ++i) cout << " " << b[i] ;
	cout << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
