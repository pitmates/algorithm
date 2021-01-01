#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 300300;
ll dp[N][4];
char s[N];

int main()
{
#ifdef PIT
freopen("628b.in", "r", stdin);
#endif // PIT
    while(~scanf("%s", s)) {
        int len = strlen(s);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= len; ++i) {
            int k = s[i-1] - '0';
            k %= 4;
            dp[i][k]++;
            for(int j = 0; j < 4; ++j) dp[i][(j*10+k)%4] += dp[i-1][j];
        }
        ll ans = 0LL;
        for(int i = 1; i <= len; ++i) ans += dp[i][0];
        printf("%I64d\n", ans);
    }
    return 0;
}
