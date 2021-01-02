#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dg[20], t;
ll a, b;
int k;
ll f[20][200];


ll dfs(int i, ll s, int v, bool flag, bool e) {
    if(i == -1) {
            if(v == k) {
                    printf("%lld \n", s);
                    return s;
            }
            return 0;
    }
    if(!e && ~f[i][v]) return f[i][v];
    int u = e ? dg[i] : 9;
    ll res = 0;
    int j = ((t-i)&1) ? 1 : -1;
    for(int d = 0; d <= u; ++d) {
        res += dfs(i-1, s*10+d, v+j*d, flag || d, e && (d == u));
    }
    return e ? res : res = f[i][v];
}

ll solve(ll a) {
    ll v = a; t = 0;
    while(v) dg[t++] = v % 10, v /= 10;
    memset(f, -1, sizeof f);
    return dfs(t-1, 0, 0, 0, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> a >> b >> k;
    solve(a-1);
//    cout << solve(b) - solve(a-1) << endl;
    return 0;
}
