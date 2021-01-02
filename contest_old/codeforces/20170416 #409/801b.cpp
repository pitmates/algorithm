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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
int _time_zlp = clock();
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	int n = sz(s1), flag = 1;
	string s = s2;
	rep(i, 0, n) if(s1[i] < s2[i]) {
		flag = 0;	break;
	}
	if(flag) cout << s << endl;
	else cout << -1 << endl;
	
#ifdef PIT
debug("Time: %f s\n", double(clock()-_time_zlp)/CLOCKS_PER_SEC);
#endif //PIT
	return 0;
}
