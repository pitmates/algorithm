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
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k, a, b;
    cin >> k >> a >> b;
    if(a / k == 0 && (b % k)) {
        cout << "-1";
        return 0;
    }
    if((a % k) && b / k == 0) {
        cout << "-1";
        return 0;
    }
    int z = a / k + b / k;
    if(z == 0) cout << "-1";
    else cout << z;

    return 0;
}
