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
const int N = 123456;

int a[N];

int main()
{
#ifdef PIT
freopen("A-large.in", "r", stdin);
freopen("A-large.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;

    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
		int n, k;
		cin >> n >> k;

		int m = n % k;

		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a+n);
		for (int i = n; i < n+m; ++i) a[i] = -1;
		int t = 1;
		int ans = 0, s = 0;
		// cout << "ss" << endl;
		for (int i = 0; i < n+m; ++i) {
		    //cout << i << " " << a[i] << " " << t << endl;

		    if (a[i] >= t) ++s;
		    if (s == k) {
		        ++t;
		        ans += s;
		        s = 0;
		    }
		    //++t;
		}
		ans += s;
		cout << ans << endl;



    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*
1000 1
2 1 2 3 3 3 1 1 3 2 1 3 2 2 1 2 3 2 1 3 2 1 2 2 2 2 2 1 3 3 1 1 1 3 2 1 3 2 2 3 2 3 1 1 2 2 2 2 3 3 2 2 1 3 1 3 2 3 3 1 3 1 3 3 1 1 1 1 3 3 3 2 3 1 2 1 3 1 3 2 1 1 1 2 1 2 1 3 2 1 2 1 2 1 3 3 2 1 3 2 1 3 1 3 1 2 1 3 3 2 2 1 3 3 3 2 2 3 1 3 1 2 1 3 3 1 2 1 2 2 3 2 3 3 2 3 2 3 3 2 2 2 3 1 2 2 2 3 2 1 3 3 3 1 3 3 2 2 3 3 1 3 3 3 3 1 3 3 1 3 1 2 2 1 3 3 3 2 1 2 2 3 2 2 1 1 2 3 2 2 2 1 2 2 3 2 3 1 1 1 3 3 3 1 3 3 1 2 2 1 1 1 1 2 3 2 3 2 1 2 3 1 2 1 3 3 1 2 3 1 3 2 3 3 3 3 2 1 3 1 2 1 2 3 3 1 3 2 2 1 1 3 1 3 1 1 2 1 3 2 3 3 3 3 3 3 3 2 1 3 3 3 3 1 3 3 3 2 2 1 2 3 1 1 3 2 2 2 2 2 3 1 3 3 1 2 1 1 1 1 1 3 1 1 3 1 1 2 3 2 1 2 2 1 3 1 3 2 2 2 1 2 3 3 2 1 1 2 1 2 3 2 2 1 3 2 1 1 1 1 2 2 1 2 1 3 2 3 2 2 2 3 3 2 2 2 2 3 3 1 3 1 2 1 1 2 3 3 2 1 3 1 3 3 2 1 1 1 1 2 2 3 2 3 1 3 1 1 3 2 1 2 2 3 3 3 2 2 2 3 3 3 3 1 3 2 1 3 1 2 2 2 2 3 1 3 3 3 3 3 1 1 2 3 1 2 2 2 2 2 1 2 1 2 2 3 1 1 1 1 2 2 1 1 3 2 1 2 1 1 2 2 2 2 2 3 3 2 1 2 3 2 1 3 1 3 2 2 3 3 3 2 2 3 2 1 3 3 3 3 1 2 3 3 3 2 2 3 3 3 2 2 2 3 1 3 2 1 2 2 3 2 1 2 2 3 3 1 3 3 1 1 1 1 1 1 3 2 3 2 2 2 1 3 1 2 3 3 3 1 2 1 3 2 2 2 1 2 3 1 1 3 2 2 2 2 2 1 3 2 2 2 1 3 2 1 3 2 1 2 1 2 2 3 1 2 2 3 3 1 3 1 1 2 2 2 3 1 3 1 3 3 3 3 2 2 2 2 1 3 1 1 3 3 1 3 2 2 2 1 3 3 2 1 1 1 3 1 2 3 2 2 2 3 2 2 1 3 3 1 1 1 2 3 1 2 2 3 1 2 1 3 1 3 1 2 1 1 3 2 3 3 1 3 2 3 1 2 3 3 1 3 2 2 2 3 2 2 2 2 3 3 3 3 3 3 2 1 1 1 3 1 3 1 3 1 3 1 1 3 1 2 3 3 3 2 2 2 3 3 1 3 3 3 2 3 3 1 3 1 2 2 1 1 3 2 3 3 2 1 3 3 2 3 2 2 1 3 1 2 3 2 1 3 2 3 2 2 1 1 2 2 3 3 1 1 1 1 3 3 1 3 3 2 2 2 1 1 1 1 2 1 2 2 1 3 2 2 1 3 3 3 1 3 3 2 1 3 2 3 3 3 1 1 1 2 2 2 3 3 3 1 2 3 3 2 3 2 1 2 1 1 1 3 1 3 1 1 1 1 1 1 3 2 1 2 1 3 1 1 3 3 1 2 2 1 3 2 1 1 3 1 2 1 1 2 2 3 3 3 3 1 3 3 2 2 1 3 1 1 3 1 2 2 2 1 2 3 3 3 3 3 1 2 1 2 1 2 1 1 2 1 2 2 1 3 3 1 2 2 3 3 3 1 1 3 2 3 2 2 3 2 1 1 2 2 2 2 1 3 3 2 1 1 1 1 1 1 3 3 2 2 2 3 3 3 2 1 3 1 2 3 3 1 3 1 2 2 3 1 2 3 2 3 3 2 3 1 3 2 1 2 1 2 2 3 3 1 2 3 1 1 2 2 1 2 3 1 3 1 1 3 3 2 2 1 2 2 1 2 2 1 1 2 1 3 3 3 3 1 2 2 1 1 3 3 2 3 3 2 3 1 1 3 3 3 1 2 2 1 3 1 3 1 2 3 1 1 3 3

 */