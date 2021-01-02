#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 1e6+3;

char s[N];
int n;
int st[N];
ll dp[N];

void solve() {
    ll ans = 0;
    int top = -1;
    n = strlen(s);
    rep(i, 0, n) {
        if(s[i] == '(') st[++top] = i;
        else if(top > -1) {
            int pre = st[top--];
            dp[i] = (1 + dp[pre-1]);
        }
        ans += dp[i];
    }
    printf("%lld\n", ans);
    return ;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    scanf("%s", s);
    solve();
    return 0;
}
