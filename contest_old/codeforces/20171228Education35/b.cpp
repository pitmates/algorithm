//
// Created by pitmates on 2017/12/28.
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
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b) swap(a, b);
    int mi = 0;
    for (int i = 1; i < n; ++i) {
        int xa = a / i;
        int xb = b / (n-i);
        if (xa == 0 || xb == 0) continue;
        mi = max(mi, min(xa, xb));
    }
    cout << mi << endl;

#ifdef PIT
    flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
