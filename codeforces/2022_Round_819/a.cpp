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
        int mx = *max_element(a.begin(), a.end());
        int mi = *min_element(a.begin(), a.end());
        int res = max(mx-a[0], a[n-1]-mi);
        for (int i = 0; i < n; ++i) {
            int x = a[i] - a[(i+1)%n];
            res = max(res, x);
        }
        cout << res << endl;
    }

    return 0;
}