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
string s;
int n;

bool judge(int g[], int qe, int id) {
	int f = 1;
	rep(i, 0, 26) if(g[i] > 1) f = 0;
	if(f) {
		int l = 0;
		rep(i, id, id+26) {
			if(s[i] == '?') {
				while(g[l]) ++l;
				g[l] = 1;
				s[i] = 'A' + l;
			}
		}
		rep(i, 0, n) if(s[i] == '?') s[i] = 'A';
		cout << s << endl;
		return 1;
	}
	return 0;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	n = sz(s);
	int qe = 0;
	if(n < 26) {
		cout << -1 << endl; 
		return 0;
	}
	int g[27];
	zero(g);
	rep(i, 0, 26) 
		if(s[i] == '?') ++qe;
		else g[s[i]-'A']++;
	int f = judge(g, qe, 0);
	if(f) return 0;
	for(int i = 26; i < n; ++i) {
		if(s[i-26] == '?') --qe;
		else --g[s[i-26]-'A'];
		if(s[i] == '?') ++qe;
		else ++g[s[i]-'A'];
		f = judge(g, qe, i-25);
		if(f) return 0;
	}
	cout << -1 << endl;
	return 0;
}
