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
const int N = 100100;
double dp[N];
int n;

void init(){
	dp[1] = 0;
	rep(i, 2, N) {
		int t = 0; 
		for(int j = 1; j * j <= i; ++j){
			if(i % j) continue;
			dp[i] += dp[j]; ++t;
			if(j != i/j) dp[i] += dp[i/j], ++t;
		}
		(dp[i] += t) /= (t-1);
	}
	return ;
}

bool g[N];
int pr[N], t;

void prime() {
	zero(g); t = 0;
	rep(i, 2, N) {
		if(!g[i]) pr[t++] = i;
		for(int j = 0, k; j < t && (k = pr[j]*i) < N; ++j) {
			g[k] = 1;
			if(i % pr[j] == 0) break;
		}
	}
	return ;
}


vector<int > deal(int x) {
	vector<int > v; v.clear();
	v.pb(1);
	for(int i = 2; i * i <= x; ++i) {
		if(x % i) continue;
		v.pb(i);
		if(i != x/i) v.pb(x/i);
	}
	return v;
}

double dfs(int x) {
	//printf("x:%d %d  ===>\n", x, g[x]);
	if(x == 1) return 0;
	if(!g[x]) return 2.;
	vector<int > v = deal(x);
	int z = sz(v);
	//printf("z:%d\n", z);
	//rep(i, 0, z) printf("%d ", v[i]); puts("");
	double ans = (z+1.)/z;
	rep(i, 0, z) {
		ans += dfs(v[i]) / z;
	}
	return ans;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	//ios_base::sync_with_stdio(false); cin.tie(0);
	int T; 
	//init();
	prime();
	for(int ic = scanf("%d", &T); T--; ic++){
		scanf("%d", &n);
		printf("Case %d: %.8f\n", ic, dfs(n));
	}

	return 0;
}
