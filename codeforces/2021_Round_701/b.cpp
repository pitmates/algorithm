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

    int n, k, q;
    cin >> n >> q >> k;
    vector<int> a(n+2, 0), b(n+2, 0), s(n+2, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[n+1] = k;
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i+1] - a[i-1] - 1;
        s[i] = b[i] + s[i-1];
    }
    // for (int i = 0; i <= n; ++i)cout << b[i] << " "; cout << endl;
    // for (int i = 0; i <= n; ++i)cout << s[i] << " "; cout << endl;

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] + a[l-1] + k - a[r+1] - r + l << endl;
    }

    return 0;
}
