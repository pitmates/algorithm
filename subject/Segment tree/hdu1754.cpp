#include <iostream>
#include <cstdio>
#include <cstring>

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;

const int N = 200200;
int mx[N<<2];
int n, m;
char c[2];

int read() {int x; scanf("%d", &x); return x; }

void PushUP(int rt) { mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);}

void build(int l, int r, int rt) {
    if(l == r) {
        mx[rt] = read();
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

void update(int p, int q, int l, int r, int rt) {
    if(l == r) {
        mx[rt] = q;
        return ;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p, q, lson);
    else update(p, q, rson);
    PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r) {
        return mx[rt];
    }
    int m = (l + r) >> 1;
    int x = 0;
    if(L <= m) x = max(x, query(L, R, lson));
    if(R > m) x = max(x, query(L, R, rson));
    return x;
}

int main()
{
    while(~scanf("%d%d", &n, &m)) {
        build(1, n, 1);
        while(m--) {
            int a, b;
            scanf("%s", c);
            a = read(); b = read();
            if(c[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
            else update(a, b, 1, n, 1);
        }
    }
    return 0;
}
