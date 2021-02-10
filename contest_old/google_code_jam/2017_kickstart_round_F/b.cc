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

const int N = 1010;

int a[N], s[N];
int n;
int E;

int solve() {
	sort(a, a+n);
	s[0] = a[0];
	for (int i = 1; i < n; ++i) s[i] = s[i-1] + a[i];
	if (E > s[n-1]) return n;
	if (E <= s[0]) return 0;
	int d = lower_bound(s, s+n, E) - s;
	int mx = d, ans = d;
	int tmp = E - s[d-1];
	int l = d, r = n-1;
	while (true) {
		if (ans > 0) {
			--ans;
			tmp += a[r];
			--r;
		} else {
			break;
		}

		while (tmp > a[l] && l <= r) {
			tmp -= a[l];
			++ans;
			++l;
		}
		mx = max(mx, ans);
	}
	return mx;
}

int main()
{
#ifdef PIT
freopen("B-large-practice.in", "r", stdin);
freopen("B-large-practice.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
        cin >> E >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        cout << solve() << endl;
        
    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}