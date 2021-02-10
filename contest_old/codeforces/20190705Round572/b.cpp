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

//    cout << (1LL<<31)-1 << endl;
    int n; cin >> n;
    vector<int > a(n, 0), g(n, 0), b(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    g[n-1] = g[n-2] = 1;
    int x = 0;
    for (; x < n-2; ++x) {
        if (a[x] + a[n-2] > a[n-1]) break;
    }
//    cout << "x = " << x << endl;
    if (x >= n-2) cout << "NO" << endl;
    else {
        b[0] = a[x], b[n-1] = a[n-1], b[n-2] = a[n-2];
        g[x] = 1;
        int y = 1;
        for (int i = 0; i < n; ++i) {
            if (g[i] == 1) continue;
            b[y++] = a[i];
        }
//        for (int i = 0 ; i < n; ++i) cout << " " << b[i]; cout << endl;
        int z = 0;
        for (int i = 0; i < n; ++i) {
            if (b[(n+i-1)%n] + b[(i+1)%n] <= b[i]) {
                z = 1;
                break;
            }
        }
        if (z == 1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) cout << b[i] << " ";
            cout << endl;
        }
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
