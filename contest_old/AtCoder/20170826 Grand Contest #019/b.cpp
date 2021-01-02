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

string s;
int word[30];


ll solve() {
	int n = sz(s);
	if(n == 1) return 1;
	rep(i, 0, n) word[s[i]-'a']++;
	ll num = 1LL * (n-1) * n / 2;
	rep(i, 0, 30) if(word[i] > 1) {
		ll k = 1LL * (word[i]-1) * word[i] / 2;
		num -= k;
	}
	return num+1;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	zero(word);
	cout << solve() << endl;

	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
