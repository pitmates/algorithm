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
const int N = 1000100;

ll s[N];
int n;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> s[i];
	s[n] = 0;
	int f = 0;
	for(int i = n-1; i >= 0; --i) {
		s[i]  = s[i] + s[i+1];
		if(s[i]&1) f = 1;
	}
	if(s[0]&1) cout << "First" << endl;
	else if(f) cout << "First" << endl;
	else cout << "Second" << endl;

	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
