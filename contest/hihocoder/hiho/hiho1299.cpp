#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;

const int N = 1e5+3;
int mx[N<<2];
int n, m;
int mt;
int t[N], p[N];

inline void pushup(int rt) { mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);}

void update(int t, int p, int l, int r, int rt) {
    if(l == r) {
        mx[rt] = max(mx[rt], p);
        return ;
    }
    int m = l + r >> 1;
    if(t <= m) update(t, p, lson);
    else update(t, p, rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r) return mx[rt];
    int m = l + r >> 1;
    int ret = -1;
    if(L <= m) ret = max(ret, query(L, R, lson));
    if(R > m) ret = max(ret, query(L, R, rson));
    return ret;
}

int main()
{
    scanf("%d %d", &n, &m);
    memset(mx, -1, sizeof mx);
    mt = -1;
    rep(i, 0, n) {
        scanf("%d %d", t+i, p+i);
        mt = max(mt, t[i]);
    }
    rep(i, 0, n) update(t[i], p[i], 1, mt, 1);
    rep(i, 0, m) {
        int l, r;
        scanf("%d %d", &l, &r);
        int s = query(l, r, 1, mt, 1);
        if(s == -1) puts("None");
        else printf("%d\n", s);
    }
    return 0;
}
