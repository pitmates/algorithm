#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

inline int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

ll f[20][255][25<<1];
int dg[20];
int k;
int o[2525], g[2525][10], mo[255][10], oo[25<<1];

void pc() {
    k = 0;
    for(int i = 1; i < 2521; ++i) if(2520%i == 0)
        o[i] = ++k, oo[k] = i;
    for(int j = 0; j < 10; ++j){
        for(int i = 1, q = j ? j : 1; i <= k; ++i)
            g[oo[i]][j] = oo[i]*q/gcd(oo[i], q) ;
        for(int i = 0; i < 252; ++i)
            mo[i][j] = (i*10+j) % 252;
    }
    return ;
}

ll dfs(int i, int s, int t, bool e) {
    if(i == -1) return s % t == 0;
    if(!e && ~f[i][s][o[t]]) return f[i][s][o[t]];
    int u = e ? dg[i] : 9;
    ll res = 0;
    for(int d = 0; d <= u; ++d) {
        res += dfs(i-1, i ? mo[s][d] : (s*10+d), g[t][d], e&&d==u);
    }
    return e ? res : f[i][s][o[t]] = res;
}

ll solve(ll x) {
    int len = 0;
    for(; x; x /= 10) dg[len++] = x % 10;
    return dfs(len-1, 0, 1, 1);
}

int main()
{
    pc();
    int T;
    scanf("%d", &T);
    memset(f, -1, sizeof f);
    ll l, r;
    while(T--) {
        scanf("%I64d %I64d", &l, &r);
        printf("%I64d\n", solve(r) - solve(l-1));
    }
    return 0;
}
