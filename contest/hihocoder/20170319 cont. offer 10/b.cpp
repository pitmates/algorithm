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
const ll mo = (ll)1e9+7;
const int N = 100100;

ll f[N][4][3]; // 0: O

ll dfs(int i, int s, int t, bool e) {
//printf("i:%d s:%d t:%d e:%d\n", i, s, t, e);
    if(i == 0) return s<3 && t<2;
    if(!e && ~f[i][s][t]) return f[i][s][t];
  	int u = 3;
    ll res = 0;
    for(int d = 1; d <= u; ++d) {
    	//printf("i:%d d:%d ================\n", i, d);
    	if(s == 2 && d == 2) continue;
    	if(t == 1 && d == u) continue;
        res = (res+dfs(i-1, d==2?s+1:0, t||(d==u), e&&d==u))%mo;
    }
    //printf("i:%d s:%d t:%d e:%d res:%I64d  ++++++\n", i, s, t, e, res);
    return e ? res : f[i][s][t] = res;
}


int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	memset(f, -1, sizeof f);
	ll res = dfs(n, 0, 0, 1);

	cout << res << endl;
	
	return 0;
}
