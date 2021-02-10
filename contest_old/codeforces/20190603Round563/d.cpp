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

    int n, x;
    vector<int > ans, e;
    cin >> n >> x;
//    if (n == 1) {
//        if (x == 1) cout << 0 << endl;
//        else cout << 1 << endl << 1 << endl;
//    }

    for (int i = 0, y = 1; i < n; ++i) {
        if (y <= x && y * 2 > x) {
            y *= 2;
        }
        else {
            e.pb(y);
            y *= 2;
        }
    }

//    for (auto z : e) cout << z << " " ;
    for (auto z : e) {
        ans.pb(z);
        int len = ans.size();
        for (int i = 0; i < len-1; ++i) ans.pb(ans[i]);
    }
    cout << ans.size() << endl;
    if (ans.size() != 0) {
        for (auto y : ans) cout << y << " ";
        cout << endl;
    }



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
