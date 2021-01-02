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
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 30;

string s, c;
pair<char, char > p[N];
bool g[N];
int t; 

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	cin >> c;
	int n = sz(s), flag = 1;
	zero(g);
	t = 0;
	rep(i, 0, n) {
		if(s[i] != c[i]) {
			if(g[s[i]-'a'] || g[c[i]-'a']) {
				flag = 0;
				break;
			}
			p[t] = {s[i], c[i]};
			rep(j, i, n) {
				if(c[j] == p[t].fi) {
					if(s[j] == p[t].se)
						c[j] = p[t].se;
					else flag = 0;
				}
				else if(c[j] == p[t].se) {
					if(s[j] == p[t].fi) 
						c[j] = p[t].fi;
					else flag = 0;
				}
			}
			++t;
		}
		else g[s[i]-'a'] = 1;
		if(!flag) break;
	}
	if(flag == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << t << endl;
	rep(i, 0, t) cout << p[i].fi << " " << p[i].se << endl;
	return 0;
}
