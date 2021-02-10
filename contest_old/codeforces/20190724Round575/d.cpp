//
// coded by zhuangliupeng
//

// d1 & d2 solution

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
    char c[] = {'R', 'G', 'B'};
    map<char, int > mc;
    mc['R'] = 1, mc['G'] = 2, mc['B'] = 3;
    while (T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if (k == 1) {
            cout << 0 << endl;
            continue;
        }
        vector<int > dis(n, 0);
        for (int i = 0; i < n; ++i) {
            int x = mc[c[i%3]] - mc[s[i]], y = 0;
            if (x == -1 || x == 2) y = 1;
            else if (x == -2 || x == 1) y = 2;
            dis[i] = y;
        }

//        for (int i = 0; i < n; ++i) cout << dis[i] << " "; cout << endl;

        int ans = k;
        for (int u = 0; u < 3; ++u) {
            int cnt = 0, mi = k;
            for (int i = 0; i < k; ++i) if (dis[i] != u) ++cnt;
            mi = cnt;
            for (int i = k, l = 1; i < n; ++i, ++l) {
                if (dis[l-1] == u) ++cnt;
                if (dis[i] == u) --cnt;
                mi = min(mi, cnt);
            }
            ans = min(ans, mi);
        }

        cout << ans << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
