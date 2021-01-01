#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long

using namespace std;
const int N = 103;
int a[N];

inline int gcd(int x, int y) {return y ? gcd(y, x%y) : x;}

inline void lcm(int& x, int y) { x = x / gcd(x, y) * y; }

int main()
{
    int n, ans = 1;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        int now = a[i], t;
        for(t = 1; t && now != i; ++t, now = a[now]) ;
        lcm(ans, t);
    }
    cout << ans;
    return 0;
}
