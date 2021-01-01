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
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
char consonants[20] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
						'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
int n;

void dfs(int g, int d, string s) {
	if(d == n) {
		cout << s << endl;
		return ;
	}
	if(g&1) for(int i = 0; i < 5; ++i) dfs(g^1, d+1, s+vowels[i]);
	else for(int i = 0; i < 20; ++i) dfs(g^1, d+1, s+consonants[i]);
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	dfs(0, 0, "");
	dfs(1, 0, "");
	return 0;
}
