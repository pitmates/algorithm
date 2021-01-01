#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 110;
char c[N];
int f[N][N];

int dfs(int l, int r) {
    if(l >= r) return f[l][r] = 0;
    if(~f[l][r]) return f[l][r];
    int res = min(dfs(l, r-1), dfs(l+1, r)) + 1;
    res = min(res, dfs(l+1, r-1)+1);
    if(c[l] == c[r]) res = min(res, dfs(l+1, r-1));
    return f[l][r] = res;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    scanf("%s", c);
    memset(f, -1, sizeof f);
    int len = strlen(c);
    printf("%d\n", dfs(0, len-1));
    return 0;
}
