#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 100100;
int a[N], b[31] = {1};
int n;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT

    for(int i = 1; i < 31; ++i) b[i] = b[i-1] << 1;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", a+i);
    sort(a, a+n);
    ll s = 0LL;
    rep(i, 0, n) {
        rep(j, 0, 31) {
            int x = b[j] - a[i];
            if(x < a[i]) continue;
            int y = lower_bound(a+i+1, a+n, x) - a;
            int z = upper_bound(a+i+1, a+n, x) - a;
            s += z - y;
        }
    }
    printf("%I64d\n", s);
    return 0;
}
