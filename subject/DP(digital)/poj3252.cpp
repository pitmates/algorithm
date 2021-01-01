#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 36;

int f[N][N][N];
int dg[N];

int dfs(int i, int z, int o, bool s, bool e) {
    if(i == -1) return z >= o;
    if(!e && ~f[i][z][o]) return f[i][z][o];
    int res = 0;
    int u = e ? dg[i] : 1;
    for(int d = 0; d <= u; ++d){
        res += dfs(i-1, (!s&&(d==0))?0:(z+(d==0)), (!s&&(d==0))?0:(o+(d==1)), s||(d==1), e&&(d==u));
    }
    return e ? res : f[i][z][o] = res;
}

int solve(int x) {
    int len;
    for(len = 0; x; x>>=1) dg[len++] = (x&1);
    memset(f, -1, sizeof f);
    return dfs(len-1, 0, 0, 0, 1);
}

int main()
{
#ifdef PIT
freopen("poj3252.in", "r", stdin);
#endif // PIT
    int st, fi;
    while(~scanf("%d %d", &st, &fi)) {
        printf("%d\n", solve(fi) - solve(st-1));
    }
    return 0;
}
