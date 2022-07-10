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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        vector<ll> s(n, 0);
        int k = n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] > x) {
            cout << 0 << endl;
            continue;
        }
        s[0] = a[0];
        for (int i = 1; i < n; ++i) {
            s[i] = s[i-1] + a[i];
            if (s[i-1] <= x && s[i] > x) {
                k = i;
                break;
            }
        }

        // cout << " k: == " << k << endl;

        ll res = k;
        int ds = 0;
        while (k > 0) {
            int d = (x - s[k-1]) / k;
            d = d - ds;
            ds += d;
            res += k * d;
            k --;
        }
        cout << res << endl;
    }

    return 0;
}
