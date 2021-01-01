#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long
#define mp make_pair
#define fi first
#define se second

using namespace std;
const int N = 1010;
char c[N];
bool g[N][N];
pair<int, int > p[N*N];
int n, m, t;

void solve() {
    int col = 0, x, y, z;
    rep(i, 1, n) {
        x = 0;
        rep(j, 1, m) if(g[i][j]) ++x;
        col += (x > 1);
    }
    if(col > 1) {
        puts("NO");
        return ;
    }

    col = 0;
    rep(i, 1, m) {
        x = 0;
        rep(j, 1, n) if(g[j][i]) ++x;
        col += (x > 1);
    }
    if(col > 1) {
        puts("NO");
        return ;
    }

    bool f = 0;
    int u, v;
    x = y = 0;
    rep(i, 1, n) {
        rep(j, 1, m)  if(g[i][j]) {
                x = i; y = j; f = 1;
                break;
            }
        if(f) break;
    }
    if(!x && !y) {
        puts("YES\n1 1");
        return ;
    }

    f = 0;
    rep(i, 1, m) {
        z = 0;
        rep(j, 0, t) {
            if(p[j].fi == x || p[j].se == i) ++z;
        }
        if(z == t) {
            f = 1;
            u = x;
            v = i;
            break;
        }
    }
    if(f) {
        puts("YES");
        printf("%d %d\n", u, v);
        return ;
    }

    rep(i, 1, n) {
        z = 0;
        rep(j, 0, t) {
            if(p[j].fi == i || p[j].se == y) ++z;
        }
        if(z == t) {
            f = 1;
            u = i;
            v = y;
            break;
        }
    }
    if(f) {
        puts("YES");
        printf("%d %d\n", u, v);
        return ;
    }

    puts("NO");
    return ;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    scanf("%d %d", &n, &m);
    memset(g, 0, sizeof g);
    t = 0;
    rep(i, 1, n) {
        scanf("%s", c+1);
        rep(j, 1, m) {
            if(c[j] == '.') g[i][j] = 0;
            else g[i][j] = 1, p[t++] = mp(i, j);
        }
    }
    solve();
    return 0;
}
