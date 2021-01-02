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
	int n;
	cin >> n;
	vector<int > sd; sd.clear();
	int nsd = 0, ot = 0, ans = 0;
	while(n--) {
		int t, s;
		cin >> t;
		if(t == 1) {
			cin >> s;
			nsd = s;
			while(!sd.empty() && nsd > sd.back()) {
				sd.pop_back(); ++ans;
			}
		}
		else if(t == 2) ans += ot, ot = 0;
		else if(t == 3) {
			cin >> s;
			sd.pb(s);
			while(!sd.empty() && nsd > sd.back()) {
				sd.pop_back(); ++ans;
			}
		}
		else if(t == 4) ot = 0;
		else if(t == 5) sd.clear();
		else ++ot;
	}
	cout << ans;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
