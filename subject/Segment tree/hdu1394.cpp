#include <iostream>
#include <cstdio>
#include <cstring>

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;

const int N = 5050;

int inv[N<<2];
int n;
int per[N];

void PushUp(int rt) { inv[rt] = inv[rt<<1] + inv[rt<<1|1];}

void build(int l, int r, int rt) {
    inv[rt] = 0;
    if(l == r) return ;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void update(int x, int l, int r, int rt) {
    if(l == r) {
        inv[rt]++;
        return ;
    }
    int m = (l + r) >> 1;
    if(x <= m) update(x, lson);
    else update(x, rson);
    PushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r) {
        return inv[rt];
    }
    int m = (l + r) >> 1;
    int res = 0;
    if(L <= m) res += query(L, R, lson);
    if(R > m) res += query(L, R, rson);
    return res;
}

int main()
{
    while(~scanf("%d", &n)) {
        build(1, n, 1);
        int s = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", per+i);
            per[i];
            s += query(per[i]+1, n, 1, n, 1);
            update(per[i]+1, 1, n, 1);
        }
        int mv = s;
        for(int i = 0; i < n; ++i) {
            s = s + n - per[i] - per[i] - 1;
            mv = min(s, mv);
        }
        printf("%d\n", mv);
    }
    return 0;
}
