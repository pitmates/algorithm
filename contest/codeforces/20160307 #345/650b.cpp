#include <bits/stdc++.h>

using namespace std;

const int N = (1<<19);

int f[N], e[N];
char s[N];
int n, a, b, t;

inline int ck_w(char c) {return c == 'w' ? b+1 : 1;}

void solve() {
    f[1] = ck_w(s[1]);
    for(int i = 2; i <= n; ++i) f[i] = f[i-1] + ck_w(s[i]) + a;
    for(int i = n; i > 0; --i) e[i] = e[i+1] + ck_w(s[i]) + a;
    int ans = 0, i, j = n+1;
    for(i = n; i > 0; --i) {
        for( ; f[i] + e[j-1] + a*min(i-1, n-j+2) <= t && j - 1 > i; --j) ;
        if(f[i] + e[j] + a*min(i-1, n-j+1) <= t) ans = max(ans, i+n-j+1);
    }
    printf("%d\n", ans);
    return ;
}

int main()
{
    scanf("%d %d %d %d", &n, &a, &b, &t);
    scanf("%s", s+1);
    solve();
    return 0;
}
