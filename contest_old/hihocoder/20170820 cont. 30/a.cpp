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
	string s, a, b;
	cin >> a >> b >> s;
	int la = sz(a), lb = sz(b), ls = sz(s);
	int minv = ls + ls;
	rep(i, 0, ls) {
		int fa = 0, fb = 0;
		if(s[i] != a[fa] && s[i] != b[fb]) continue;
		// printf("%d %c\n", i, s[i]);
		vector<int > idx; idx.clear();
		if(s[i] == a[fa]) {
			for(int j = i; j < ls; ++j) {
				if(s[j] == a[fa]) ++fa, idx.pb(j);
			}
		}
		for(int j = i; j < ls; ++j) {
			if(s[j] == a[fa]) ++fa;
			else if(s[j] == b[fb]) ++fb;
			// printf("j: %d  fa: %d  fb: %d\n", j, fa, fb);
			if(fa == la && fb == lb) {len = j-i+1; break;}
		}
		if(fa != la || fb != lb) minv = min(ls+ls, minv);
		else minv = min(minv, len);
	}
	if(minv == ls+ls) cout << -1 << endl;
	else cout << minv << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
