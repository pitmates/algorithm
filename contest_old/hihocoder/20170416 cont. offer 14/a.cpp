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
const int N = 1010;

int n;
int A[N];

map<int, vector<pii > > mmp;

bool compare(pii x, pii y) {
	return (x.fi != y.fi && x.se != y.se) && (x.fi != y.se && x.se != y.fi);
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> A[i];
	sort(A, A+n);
	mmp.clear();
	ll ans = 0;
	rep(i, 0, n) rep(j, i+1, n) {
		int x = A[i] + A[j];
		pii y = {i, j};
		for(auto & u : mmp[x]) {
			if(compare(u, y)) ++ans;
		}
		
		mmp[x].pb({i, j}); 
	}
	cout << (ans<<1) << endl;
	return 0;
}
