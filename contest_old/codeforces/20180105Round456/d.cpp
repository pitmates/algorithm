//
// Created by pitmates on 2018/1/5.
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
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    int nn = n - r + 1, mm = 1 + m - r;
    int mxn, mxm;
    if (nn < r) {
        mxn = nn;
        if (mm < r) {
            mxm = mm;
            if()
        }
        else {
            mxm = r;
        }
    }
    else {
        mxn = r;
        if (mm < r) {
            mxm = mm;
        }
        else {
            mxm = r;

        }
    }
    if (mm < r) mxm = mm;
    else mxm = r;


#ifdef PIT
    flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
/*
 * 36
 */