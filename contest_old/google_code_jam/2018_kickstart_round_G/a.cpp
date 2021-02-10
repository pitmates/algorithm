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
const int N = 7123;
const int M = 2e5+1234;

int n;
ll a[N];
int f[M], s[M];

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

        ll res = 0;
        int n;
        cin >> n;
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]] ++;
        }
        sort(a, a+n);
        for (int i = 0; i < n; ++i) s[a[i]] = i;
        for (int x = 0; x < n; ++x) {
            for (int y = x+1; y < n; ++y) {
                ll z = a[x] * a[y];
                if (z >= 1LL * M) continue;
                if (a[x] == 0) {
                    if (a[y] == 0) res += n-y-1;
                }
                else if (a[x] == 1) {
                    if (y < n-1 && a[y+1] == a[y]) res += s[a[y]] - y;
                }
                else res += f[z];
            }
        }
        //res += (f[0] - 1) * f[0] / 2 * (n - f[0]);
        cout << res << endl;

    }

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT

    return 0;

}