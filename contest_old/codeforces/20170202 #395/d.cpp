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
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;


int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x, y, xx, yy;
    cin >> n;
    cout << "YES" << endl;
    rep(i, 0, n) {
        cin >> x >> y >> xx >> yy;
        int z = ((x % 2 + 2) % 2) * 2 + (y % 2 + 2) % 2 + 1;
        cout << z << endl;
    }
    return 0;
}
