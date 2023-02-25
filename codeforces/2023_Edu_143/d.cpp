#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll M = 998244353;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    ll ans = 1;
    for (int i = 0; i < n; i += 3) {
        vector<int> a = {w[i], w[i+1], w[i+2]};
        sort(a.begin(), a.end());
        int res = 1;
        if (a[0] == a[2]) res = 3;
        else if (a[0] == a[1]) res = 2;
        ans = ans * res % M;
    }

    auto calcFac = [&](int k) {
        ll mul = 1;
        for (int i = 2; i <= k; ++i) {
            mul = mul * i % M;
        }

        int y = M - 2;
        ll x = 1;
        while (y) {
            if (y&1) x = x * mul % M;
            mul = mul * mul % M;
            y >>= 1;
        }
        return x;
    };
    
    auto C = [&](int n, int k) {
        ll res = 1;
        for (int i = 0; i < k; ++i) {
            res = res * (n - i) % M;
        }
        return res * calcFac(k) % M;
    };

    ans = ans * C(n/3, n/6) % M;
    
    cout << ans << endl;

    return 0;
}