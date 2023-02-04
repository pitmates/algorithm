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
    for (int iT = 1; iT <= T; ++iT) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        for (int i = 0; i < n-1; ++i) {
            int id = min_element(a.begin()+i, a.end()) - a.begin();
            ans += id - i + 1;
            reverse(a.begin()+i, a.begin()+id+1);
            // for (auto x : a) cout << x << " "; cout << endl;
        }
        cout << "Case #" << iT << ": " << ans << endl;
    }

    return 0;
}
