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

    int T; cin >> T;
    for (int icase = 1; icase <= T; ++icase) {
        cout << "Case #" << icase << ": ";
        int m; cin >> m;
        int sum = 0;
        vector<int> a(12);
        int t = 0;
        for (int i = 0; i < m; ++i) {
            int pi, ni;
            cin >> pi >> ni;
            for (int j = 0; j < ni; ++j) a[t++] = pi;
            sum += pi * ni;
        }
        int n = (1 << t);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int sum_i = sum, p = 1;
            for (int j = 0; j < t; ++j) {
                if (i & (1 << j)) {
                    sum_i -= a[j];
                    p *= a[j];
                }
                if (p > sum) break;
            }
            if (p == sum_i) ans = max(ans, p);
        }
        
        cout << ans << endl;
    }

    return 0;
}
