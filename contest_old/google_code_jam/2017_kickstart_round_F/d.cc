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
const int N = 103;

int area[N];
int ans[N*N];
int n;

int main()
{
#ifdef PIT
freopen("D-large.in", "r", stdin);
freopen("D-large.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

	for (int i = 1; i < N; ++i) area[i] = i * i;

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
        cin >> n;
        for (int i = 0; i < n; ++i) ans[i] = n;
        ans[n] = 0;
        for (int i = n; i >= 0; --i) {
        	for (int j = 1; j < N; ++j) {
        		if(j * j > i) break;
        		ans[i - j * j] = min(ans[i-j*j], ans[i]+1);
        	}
        }
        cout << ans[0] << endl;
    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}