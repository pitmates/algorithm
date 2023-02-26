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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int x = -1, y = -1, g = 1234567;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int gd = __gcd(a[i], a[j]);
                if (gd < g) {
                    g = gd;
                    x = i;
                    y = j;
                }
            }
        }
        if (g < 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}