#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ull unsigned long long
#define mp make_pair

using namespace std;

const int N = 20;
ull f[N];
ull k;
int dg[N], t;

void deal(ull x) {
    memset(dg, 0, sizeof dg);
    for(t = 0; x; x /= 10) dg[t++] = x % 10;
    return ;
}

ull dfs(int i, ull s, bool e) {
    if(i == -1)  return 1;
    if(!e && ~f[i]) return f[i];
    int u = e ? dg[i] : 9;
    ull res = 0;
    for(int d = 0; d <= u; ++d) {
        if(d == 4 || d == 7) continue;
        ull v = s * 10 + d;
        res += dfs(i-1, v, e && d == u);
    }
    return e ? res : f[i] = res;
}

void solve() {
    ull l = 1, r = k*5, m;
    while(l <= r) {
        m = l + r >> 1;
        deal(m);
        memset(f, -1, sizeof f);
        ull u = dfs(t-1, 0, 1), v = m - u + 1;
        if(v > k) r = m - 1;
        else if(v == k) break;
        else l = m + 1;
    }
    bool flag = 0;
    while(!flag) {
        ull v = m;
        while(v) {
            int md = (int) (v % 10);
            v /= 10;
            if(md == 4 || md == 7) flag = 1;
        }
        if(!flag) --m;
        else break;
    }
    printf("%llu\n", m);
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    cin >> k;
    solve();
    return 0;
}
