//
// coded by zhuangliupeng
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
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<int > a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int maxn  = 0, id = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > maxn) {
            maxn = a[i];
            id = i;
        }
    }
    int flag = 1;
    for (int i = id-1; i > 0; --i) {
        if (a[i] > a[i+1]) {
            flag = 0;
            break;
        }
    }
    for (int i = id+1; i <= n; ++i) {
        if (a[i] > a[i-1]) {
            flag = 0;
            break;
        }
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
