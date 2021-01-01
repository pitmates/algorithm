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
const int N = 103;

int v[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int s, k, d;
	zero(v);
	while(q--){
		cin >> s >> k >> d;
		int x = 0, ans = 0;
		for(int i = 1; i <= n; ++i) if(v[i] < s) ++x;
		if(x < k) {
			cout << "-1" << endl;
			continue;
		}
		for(int i = 1, z = 0; i <= n && z < k; ++i) 
			if(v[i] < s) v[i] = s + d - 1, ++z, ans += i;
		cout << ans << endl;
	}
	return 0;
}
