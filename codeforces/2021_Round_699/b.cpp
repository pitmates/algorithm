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
// freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
       
        vector<int> h(n);
        for (int i = 0; i < n; ++i) cin >> h[i];
        int res = 0, ans = -1;
        while (1) {
            int f = 0;
            for (int i = 1; i < n; ++i) {
                if (h[i] > h[i-1]) {
                    ++h[i-1];
                    ++res;
                    if (res == k) ans = i;
                    f = 1;
                    break;
                }
            }
            if (ans != -1 || f == 0) break;
        }
        cout << ans << endl;
    }

    return 0;
}
