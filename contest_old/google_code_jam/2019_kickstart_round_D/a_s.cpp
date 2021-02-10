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

vector<bool > g(1024, 0);

void init() {
    for (int i = 1; i < 1024; ++i) {
        int t = 0, n = i;
        while(n) { if (n&1) ++t; n >>= 1; }
        if (t&1) g[i] = 1;
    }
//    for (int i = 0; i <= 36; ++i) cout << i << ": " << g[i] << endl;
    return;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    init();

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ":";
        //cout << "Case #" << ic << ":" << endl;
        int n, q; cin >> n >> q;
        vector<int > a(n, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int ip = 0; ip < q; ++ip) {
            int p, v; cin >> p >> v;
            a[p] = v;
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                int x = 0;
                if (n-i < ans) break;
                for (int j = i; j < n; ++j) {
                    x ^= a[j];
                    if (!g[x]) ans = max(j-i+1, ans);
                }
            }
            cout << " " << ans;
        }
        cout << endl;

    }
#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}