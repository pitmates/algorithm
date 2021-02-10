//
// coded by lp.z
//

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


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;

		int n, k;
		cin >> n >> k;
		vector<int > gap(n-1), A(n);
		for (int i = 0; i < n; ++i) {
		    cin >> A[i];
		    if (i) gap[i-1] = A[i] - A[i-1];
		}

		sort(gap.begin(), gap.end());
		reverse(gap.begin(), gap.end());
		int d = (gap[0] + 1) / 2, d2 = -1;
		if (gap.size() > 1) d2 = gap[1];
		cout << max(d, d2) << endl;


    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}