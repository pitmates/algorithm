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


void draft(int u, int v, int step) {
    int b = 0, w = 0;
    if (u*3+1 < v) {
        cout << "NO" << endl;
        return;
    }

    vector<pii > bv, wv;
    bv.clear(); wv.clear();

    for (int i = 2; i < 1000000; ++i) {
        if (i&1) {
            bv.push_back({2, i}); ++b;
            wv.push_back({1, i}); ++w;
            wv.push_back({3, i}); ++w;
        }
        else {
            wv.push_back({2, i});
            ++w;
        }
        if (w >= v) break;
    }
    if (w > v) wv.pop_back();

    int id = 2;
    while (b < u) {
        bv.push_back({1, id}); ++b;
        bv.push_back({3, id}); ++b;
        id += 2;
    }
    if (b > u) bv.pop_back();

    cout << "YES" << endl;
    for (auto z : wv) {
        int x = z.first + step, y = z.second;
        cout << x << " " << y << endl;
    }
//    cout << " -- " << endl;
    for (auto z : bv) {
        int x = z.first + step, y = z.second;
        cout << x << " " << y << endl;
    }
    return;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int b, w;
        cin >> b >> w;
        if (b <= w) draft(b, w, 0);
        else draft(w, b, 1);
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
