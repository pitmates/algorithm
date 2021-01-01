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
const int N = 100100;

struct P{
	string name, rm;
	int rom;
	P(string s="", int r=0) : name(s), rom(r) {}
	bool operator<(const P& a) const {
		if(name != a.name) return name < a.name;
		return rom < a.rom;
	}
};

P p[N];
int n;

int deal(string s) {
	int res = 0;
    unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < sz(s); ++i) {
        if (i == 0 || m[s[i]] <= m[s[i - 1]]) res += m[s[i]];
        else res += m[s[i]] - 2 * m[s[i - 1]];
    }
    return res;	
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 0, n) {
		string s1, s2;
		cin >> s1 >> s2;
		p[i].name = s1;
		p[i].rm = s2;
		p[i].rom = deal(s2);
	}
	sort(p, p+n);
	for(int i = 0; i < n; ++i) cout << p[i].name << " " << p[i].rm << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
