#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int N = 2020;

char a[N], b[N];
int m, n;
int dg[N];
ll f[N][N];

inline ll add(ll x, ll y) {
    x = x + y;
    return x >= MOD ? x-MOD : x;
}

ll dfs(int i, int s, bool flag, bool e) {  // dp[i][s] , flag 表示奇数还是偶数，e代表边界
    if(i == -1) return s == 0;
    if(!e && ~f[i][s]) return f[i][s];
    ll res = 0LL;
    int u = e ? dg[i] : 9;
    for(int d = 0; d <= u; ++d) {
        if(flag == 1 && d == n) continue;
        if(flag == 0 && d != n) continue;
        res = add(res, dfs(i-1, (s*10+d)%m, flag^1, e && d==u));
    }
    return e ? res : f[i][s] = res;
}

void deal(int& len) {
    for(int i = 0; i < len; ++i) {
        if(dg[i] == 0) dg[i] = 9;
        else {
            --dg[i];
            break;
        }
    }
    return ;
}

ll solve(char c[], bool fg) {
    int len = strlen(c);
    for(int i = 0; i < len; ++i) dg[i] = c[len-1-i] - '0';
    if(fg) deal(len);
    return dfs(len-1, 0, 1, 1);
}

int main()
{
    scanf("%d %d", &m, &n);
    scanf("%s %s", a, b);
    memset(f, -1, sizeof f);
    printf("%I64d\n", add(solve(b, 0) - solve(a, 1), MOD));
    return 0;
}
