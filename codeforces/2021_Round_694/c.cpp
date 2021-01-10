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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> k(n);
        vector<int> c(m+1);
        for (int i = 0; i < n; ++i) cin >> k[i];
        for (int i = 1; i <= m; ++i) cin >> c[i];
        sort (k.begin(), k.end());
        reverse(k.begin(), k.end());
        ll ans = 0;
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            // printf("%d %d %d   %d  %lld\n", i, cnt, k[i], c[k[i]], ans);
            if (cnt > m) ans += c[k[i]];
            else {
                if (k[i] >= cnt) {
                    ans += c[cnt++];
                }
                else {
                    ans += c[k[i]];
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
