#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT

    ios_base::sync_with_stdio(false);

    int s, t, a, b, n, m;
    cin >> s >> t >> a >> b >> m >> n;
    int apple = 0, orange = 0;
    int lo;
    for(int i = 0; i < m; ++i) {
        cin >> lo;
        int x = lo + a;
        if(x >= s && x <= t) ++apple;
    }
    for(int i = 0; i < n; ++i) {
        cin >> lo;
        int y = lo + b;
        if(y >= s && y <= t) ++orange;
    }
    cout << apple << endl << orange << endl;
    return 0;
}
