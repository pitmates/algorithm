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

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	//ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	scanf("%d", &T);
	while(T--) {
		char s[110], t[110];
		scanf("%s", s);
		int n = strlen(s), q = -1;
		memset(t, false, sizeof t);
		int f = 0;
		rep(i, 0, n) {
			if(s[i] >= 'a' && s[i] <= 'z') {
				if(f) t[++q] = 'A' + (s[i] - 'a'), f = 0;
				else t[++q]  = s[i];
			}
			else if(s[i] == '_') f = 1;
			else if(s[i] >= 'A' && s[i] <= 'Z') {
				t[++q] = '_';
				t[++q] = ('a' + s[i] - 'A');
			}
		}
		printf("%s\n", t);
	}
	return 0;
}
