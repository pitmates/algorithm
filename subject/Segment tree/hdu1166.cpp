#include <bits/stdc++.h>

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1|1

using namespace std;

const int N = 50500;

int s[N<<2];

void pushup(int rt) { s[rt] = s[rt<<1] + s[rt<<1|1];}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &s[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p, int add, int l, int r, int rt) {
    if(l == r) {
        s[rt] += add;
        return ;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p, add, lson);
    else update(p, add, rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return s[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if(L <= m) ret += query(L, R, lson);
    if(R > m) ret += query(L, R, rson);
    return ret;
}

int main()
{
    int T, n, ic = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(s, 0, sizeof s);
        build(1, n, 1);
//for(int i = 0; i < (n<<2); ++i) printf("%d ", s[i]); puts("");
        char op[10];
        printf("Case %d:\n", ic++);
        while(scanf("%s", op)) {
            if(op[0] == 'E') break;
            int a, b;
            scanf("%d %d", &a, &b);
            if(op[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
            else if(op[0] == 'A') update(a, b, 1, n, 1);
            else update(a, -b, 1, n, 1);
        }
    }
    return 0;
}
