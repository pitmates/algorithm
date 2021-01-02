#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int M = 1e9+7;
const int N = 1e6+7;
int h[N];
ll dp, v;
int n;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", h+i), --h[i];
    dp = v = 0;
    rep(i, 1, n) {
        int ml = min(h[i], h[i-1]), mr = min(h[i], h[i+1]), mm = min(ml, mr);
        dp = (h[i] + ml * v % M + dp) % M;
        v = (mr + mm * v % M) % M;
    }
    printf("%I64d\n", dp);
    return 0;
}
