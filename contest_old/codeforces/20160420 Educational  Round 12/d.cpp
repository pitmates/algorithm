#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int M = 2e6+3;
const int N = 1001;

int n;
int num[N];
int odd[N], even[N];
int zero;
int co, ce;

bool g[M];
int p[M], t;

void prime() {
    memset(g, 0, sizeof g); t = 0;
    p[t++] = 2; g[4] = 1;
    for(int i = 3; i < M; i += 2) {
        if(!g[i]) p[t++] = i;
        for(int j = 0, k; j < t && (k = p[j]*i) < M; ++j) {
            g[k] = 1;
            if(i % p[j] == 0) break;
        }
    }
    return ;
}

void solve(int zero) {
    if(zero > 1) {
        printf("%d\n", zero);
        rep(i, 0, zero) printf("1 ");
        puts("");
        return ;
    }
    int x, y, z, flag = 0, pm = 0;
    rep(i, 0, co) {
        int ido = lower_bound(p, p+t, odd[i]) - p;
        if(p[ido] == odd[i]) x = odd[i], pm = 1;
        rep(j, 0, ce) {
            z = odd[i] + even[j];
            int idx = lower_bound(p, p+t, z) - p;
            if(z == p[idx]) {
                x = odd[i], y = even[j], pm = 2;
                break;
            }
        }
        if(pm == 2) break;
    }
    if(!pm) {
        if(even[0] == 2) puts("1\n2");
        else if(zero) puts("1\n1");
        else printf("1\n%d\n", num[0]);
    }
    else {
        printf("%d\n", pm);
        if(pm == 1) printf("%d\n", x);
        else printf("%d %d\n", x, y);
    }
    return ;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT

    ios_base::sync_with_stdio(false);

    prime();
    scanf("%d", &n);
    odd[0] = even[0] = zero = co = ce = 0;
    rep(i, 0, n) {
        int x;
        scanf("%d", &x); num[i] = x;
        if(x == 1) zero ++;
        else if(x&1) odd[co++] = x;
        else even[ce++] = x;
    }
    sort(odd, odd + co);
    sort(even, even + ce);
    co = unique(odd, odd+co) - odd;
    ce = unique(even, even+ce) - even;

    if(zero > 0) {
        int x = 0, flag = 0;
        rep(i, 0, ce) {
            x = even[i] + 1;
            int idx = lower_bound(p, p+t, x) - p;
            if(p[idx] == x) {flag = 1; break;}
        }
        if(!flag) solve(zero);
        else {
            printf("%d\n", zero+1);
            printf("%d ", x-1);
            rep(i, 0, zero) printf("1 ");
            puts("");
        }
    }
    else solve(zero);
    return 0;
}
