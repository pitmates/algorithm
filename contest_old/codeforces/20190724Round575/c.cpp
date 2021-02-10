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

const int M = 112345;
const int N = 100000;


struct P{
    int x, y;
    int f[5];
    P() {}
    void in() {
        cin >> x >> y;
        for (int i = 1; i < 5; ++i) cin >> f[i];
        return ;
    }
};

P p[M];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    for (int ic = 1; ic <= T; ++ic) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) p[i].in();
        int minx = -N, maxx = N, miny = -N, maxy = N;
        int flag = 1;

        for (int i = 0; i < n; ++i) {
            int f1 = p[i].f[1], f2 = p[i].f[2], f3 = p[i].f[3], f4 = p[i].f[4];

            if (f1 == 0) minx = max(minx, p[i].x);
            if (f3 == 0) maxx = min(maxx, p[i].x);
            if (f2 == 0) maxy = min(maxy, p[i].y);
            if (f4 == 0) miny = max(miny, p[i].y);
        }
//        cout << minx << " " << maxx << endl;
//        cout << miny << "  " << maxy << endl;


        if (minx > maxx) cout << 0 << endl;
        else if (miny > maxy) cout << 0 << endl;
        else cout << 1 << " " << minx << " " << miny << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
