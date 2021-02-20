#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m = n * (n-1) / 2;
        if (n&1) {
            int f = 0;
            for (int i = 0; i < m; ++i) {
                if (f) cout << -1 << " ";
                else cout << 1 << " ";
                f ^= 1;
            }
        }
        else {
            for (int i = 0; i < n-1; ++i) {
                if (i%2 == 0) cout << 0 << " ";
                else cout << -1 << " ";
                int f = 0;
                for (int j = i+2; j < n; ++j) {
                    if (f) cout << -1 << " ";
                    else cout << 1 << " ";
                    f ^= 1;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
