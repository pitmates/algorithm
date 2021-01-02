#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
using namespace std;
const int N = 1003;
int n;
ll m[N], r[N];

inline int gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
void ex_gcd(ll a, ll b, ll& x, ll& y) {
    if(a % b == 0) return ;
    ex_gcd(b, a%b, x, y);
    ll t = x; x = y; y = t - a/b * y;
}

ll solve() {
    ll M = m[0], R = r[0];
    rep(i, 1, n) {
        ll A = M, B = m[i], C = - R + r[i];
        ll d = gcd(A, B);
        if(C % d) return -1;
        A /= d, B /= d, C /= d;
        ll x = 0, y = 1;
        ex_gcd(A, B, x, y);
        (x *= C) %= B; // x = k1
        R += x * M; //
        M = A * m[i]; // lcm(M, m[i])
        R %= M; // min R
    }
    return R < 0 ? R + M : R;
}

int main()
{
    scanf("%d", &n);
    rep(i, 0, n) scanf("%lld %lld", m+i, r+i);
    printf("%lld\n", solve());
    return 0;
}
