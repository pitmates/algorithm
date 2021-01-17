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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int m = n - k + 1;
        int l = k - m;
        vector<int> ans(n);
        int now = 1, i = 0;
        while (l-- > 0) {
            ans[i++] = now++;
        }
        now = k;
        while (m-- > 0) {
            ans[i++] = now--;
        }
        for (int i = 0; i < k; ++i) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
