#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll M = 1e9+7;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    if (m > n) m = n;
    vector<ll> inv(n);
    inv[1] = 1;
    for (int i = 2; i <= m; ++i) {
        inv[i] = (M - M/i) * inv[M%i] % M;
    }

    ll res = 1, now = 1;
    if (m == n) res = 2, m--;
    for (int i = 1; i <= m; ++i) {
        now = (now * (n-i+1) % M) * inv[i] % M;
        res = (now + res) % M;
    }
    
    cout << res << endl;

    return 0;
}