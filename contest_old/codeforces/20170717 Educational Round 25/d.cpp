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
const int N = 29;

int sc[N];
string s, t;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s >> t;
	vector<int > vq; vq.clear();
	zero(sc); zero(tc);
	rep(i, 0, sz(s)) {
		if(s[i] == '?') vq.pb(i);
		else sc[s[i]-'a']++;
	}
	int f = 1;
	while(f) for(auto& c : t) {
			if(sc[c-'a']) --sc[c-'a'];
			else if(!vq.empty()) s[vq.back()] = c, vq.pop_back();
			else {f = 0; break; }
		}
	cout << s;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
