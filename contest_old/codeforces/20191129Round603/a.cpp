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

    int T; cin >> T;
    while (T--) {
        vector<int > a(3);
        for (int i = 0; i < 3; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = 0, d = a[1] - a[0];
        ans += d;
        a[1] = a[0];
        a[2] -= d;
        if (a[0] + a[1] <= a[2]) ans += a[1] + a[0];
        else {
            d = a[2] - a[1];
            ans += d*2;
            ans += (a[0] - d) * 3 / 2;
        }
        cout << ans << endl;
    }



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
