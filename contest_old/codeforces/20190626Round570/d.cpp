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
const int N = 200123;

map<int, int > m;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int q; cin >> q;
    for (int ic = 1; ic <= q; ++ic) {
        int n; cin >> n;
        m.clear();
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            m[x] += 1;
        }
        vector<int > v;
        v.clear();
        for (auto x : m) v.push_back(x.second);

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        ll ans = v[0];
        int now = v[0], len = v.size();
        for (int i = 1; i < len; ++i) {
            if (v[i] >= now) {
                ans += max(0, now-1);
                now = now-1;
            }
            else {
                ans += v[i];
                now = v[i];
            }
        }
        cout << ans << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
