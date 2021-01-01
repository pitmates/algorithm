#include <bits/stdc++.h>
#define LB(x) ((x) & (-x))
using namespace std;

const int N = 50050;

int b[N];
int n;

void update(int p, int x) {
    for(int i = p; i <= n; i += LB(i)) b[i] += x;
    return ;
}

int query(int x) {
    int res = 0;
    for(int i = x; i; i -= LB(i)) res += b[i];
    return res;
}

int main() {
    int T, ic = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int x, y;
        memset(b, 0, sizeof b);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            update(i, x);
        }
        char c[10];
        printf("Case %d:\n", ic++);
        while(scanf("%s", c) && c[0] != 'E') {
            scanf("%d%d", &x,&y);
            if(c[0] == 'A') update(x, y);
            else if(c[0] == 'S') update(x, -y);
            else printf("%d\n", query(y) - query(x-1));
        }
    }
    return 0;
}
