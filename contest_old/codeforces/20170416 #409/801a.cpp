#include <bits/stdc++.h>

#ifdef PIT
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

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

int calc(string s, int n) {
	int m = 0;
	rep(i, 1, n) if(s[i] == 'K' && s[i-1] == 'V') ++m;
	return m;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
int _time_zlp = clock();
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int n = sz(s);
	int m = calc(s, n);
	rep(i, 0, n) {
		if(s[i] == 'V') s[i] = 'K';
		else s[i] = 'V';
		m = max(m, calc(s, n));
		if(s[i] == 'V') s[i] = 'K';
		else s[i] = 'V';
	}
	cout << m << endl;

#ifdef PIT
debug("Time: %f s\n", double(clock()-_time_zlp)/CLOCKS_PER_SEC);
#endif //PIT
	return 0;
}
