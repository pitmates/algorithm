#include <iostream>
#include <cstdio>
#include <cstring>

#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
const int N = 100100;

ll sum[N<<2];
ll lazy[N<<2];

void pushup(int rt) { sum[rt] = sum[rt<<1] + sum[rt<<1|1];}

void pushdown(int v, int rt) {
    if(lazy[rt]) {
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        sum[rt<<1] += lazy[rt] * (v - (v>>1));
        sum[rt<<1|1] += lazy[rt] * (v>>1);
        lazy[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if(l == r) {
        scanf("%I64d", &sum[rt]);
        return ;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && R >= r) {
        lazy[rt] += v;
        sum[rt] += v*(r-l+1);
        return ;
    }
    pushdown(r-l+1, rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r) {
        return sum[rt];
    }
    pushdown(r-l+1, rt);
    int m = l + r >> 1;
    ll res = 0;
    if(L <= m) res += query(L, R, lson);
    if(R > m) res += query(L, R, rson);
    return res;
}

int main()
{
    int n, q;
    while(~scanf("%d %d", &n, &q)) {
        build(1, n, 1);
        getchar();
        while(q--) {
            char c[2]; int a, b;
            scanf("%s %d %d", c, &a, &b);
            if(c[0] == 'Q') printf("%I64d\n", query(a, b, 1, n, 1));
            else {
                int d; scanf("%d", &d);
                update(a, b, d, 1, n, 1);
            }
        }
    }
    return 0;
}
