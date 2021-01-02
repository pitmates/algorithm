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
const ll mo = (ll)1e9+7;
const int N = 1010;

ll inv[N], f[N], invf[N];

void deal() {
	f[0] = f[1] = inv[1] = invf[1] = inv[0] = invf[0] = 1;
	rep(i, 2, N) {
		f[i] = f[i-1] * i % mo;
		inv[i] = (mo - mo/i) * inv[mo%i] % mo;
		invf[i] = invf[i-1] * inv[i] % mo;
	}
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	int T;
	deal();
	cin >> T;
	while(cin >> n >> m){
		if(n < m) swap(n, m);
		cout << ((f[n] * invf[m]) % mo) * invf[n-m] % mo << endl;
	}
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
