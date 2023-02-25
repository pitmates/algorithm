#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int b = 0, e = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x == m) ++b;
            if (y == m) ++e;
        }
        
        bool f = b > 0 && e > 0;
        cout << (f ? "YES" : "NO") << endl;
    }

    return 0;
}