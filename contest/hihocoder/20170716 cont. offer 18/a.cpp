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

ll a, b, p;

ll multi(ll x, ll y, ll mo) {
	ll z = 1LL;
	while(y) {
		if(y&1) z = (z*x) % mo;
		x = (x*x) % mo;
		y >>= 1;
	}
	return z;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
// printf("%I64d \n", multi(2LL,5LL, 7LL));
	cin >> a >> b >> p;
	ll bi = multi(b, p-2, p);
	cout << (a * bi) % p << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
