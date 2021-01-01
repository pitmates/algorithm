#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef unsigned long long ull;
const int N = 20;

ull f[N][60000];
int dg[N];

int check(int s) {
    int nu[10];
    for(int i = 0; i < 10; ++i) {
        int k = s % 3;
        s /= 3;
        if(!k) continue;
        if((i&1) && (k==1)) return 0;
        if(!(i&1) && (k==2)) return 0;
    }
    return 1;
}

int new_s(int d, int s) {
    int nu[10];
    for(int i = 0; i < 10; ++i, s /= 3) nu[i] = s % 3;

    if(nu[d] == 0) nu[d] = 1;
    else nu[d] = 3 - nu[d];
    for(int i = 9; i > -1; --i) s = s * 3 + nu[i];
    return s;
}

ull dfs(int i, int s, bool flag, bool e) {
    if(i == -1) return check(s);
    if(!e && ~f[i][s]) return f[i][s];
    int res = 0;
    int u = e ? dg[i] : 9;
    for(int d = 0; d <= u; ++d) {
        res += dfs(i-1, (flag==0&&d==0) ? 0 : new_s(d, s), flag||d>0, e&&d==u);
    }
    return e ? res : f[i][s] = res;
}


ull solve(ull x) {
    int len = 0;
    for( ; x; x /= 10) dg[len++] = x % 10;
    return dfs(len-1, 0, 0, 1);
}

int main()
{
#ifdef PIT
freopen("SPOJ BALNUM.in", "r", stdin);
#endif // PIT
    int T;
    scanf("%d", &T);
    ull a, b;
    memset(f, -1, sizeof f);
    while(T--) {
        scanf("%llu %llu", &a, &b);
        printf("%llu\n", solve(b)-solve(a-1));
    }
    return 0;
}
