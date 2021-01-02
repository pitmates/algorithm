#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

ll n, m, k;

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}

void ex_gcd(ll a, ll b, ll &x, ll &y) {
    if(a % b == 0)
        return ;

    ex_gcd(b, a%b, x, y);
    ll z = x;
    x = y;
    y = z - a/b * y;
    return ;
}

ll equation(ll a, ll b, ll c, ll &x, ll &y) {
    ll g = gcd(a, b);
    if(c % g) return -1;
    a /= g; b /= g; c /= g;
    ex_gcd(a, b, x, y);
    x = x * c;
    if(b < 0) b = -b;
    x = (x % b + b) % b;
    return x;
}

ll work(ll x, ll y, ll maxv) {
    ll a = 2*n, b = -2*m, c = -x + y;
    ll i = 0, j = 1;
    if(equation(a, b, c, i, j) == -1) return maxv+1;
    ll t = 2 * n * i + x;
//printf("(%2lld %2lld) %2lld %2lld %2lld %2lld %2lld %2lld %2lld\n", x, y, a, b, c, maxv, i, j, t);
    if(t < 0 || t > maxv) return maxv+1;
    return t;
}

ll solve(ll x, ll y) {
    ll maxv = n / gcd(n, m) * m;
    ll minv = min({work(x, y, maxv), work(x, -y, maxv), work(-x, y, maxv), work(-x, -y, maxv)});
    if(minv == maxv + 1) return -1;
    return minv;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    while(k--) {
        ll x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}
