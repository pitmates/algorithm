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
const int N = 123;

int n, m;
int a[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    memset(a, 0, sizeof a);
    for (int i = 0, _; i < m; ++i) {
        cin >> _;
        a[_]++;
    }
    int res = -1;
    if (n > m) res = 0;
    else {
        sort (a, a+N);
        int ans = 0;
        for (int i = 0; i < N; ++i) ans += a[i];
        int l = 1, r = ans / n, md ;
        while (l <= r) {
            md = (l + r) >> 1;
            int tm = 0;
            for (int i = 0; i < N; ++i) if (a[i] >= md) {
                tm += a[i] / md;
            }
            if (tm > n) l = md + 1;
            else r = md - 1;
        }
        res = l;
    }
    cout << res << endl;
    
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
