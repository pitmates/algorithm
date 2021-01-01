#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long
#define mp make_pair
#define pii pair<int, int >
using namespace std;
const int N = 22;
int n, m;
int a[N][N];
int c[N][N];

void fuzhi() {
    rep(i, 1, n) rep(j, 1, m) c[i][j] = a[i][j];
    return ;
}

void _swap(int x, int y) {
    rep(i, 1, n) swap(c[i][x], c[i][y]);
    return ;
}

int judge() {
    rep(i, 1, n) {
        int z = 0;
        rep(j, 1, m) {
            while(c[i][j] != j) {
                ++z;
                swap(c[i][j], c[i][c[i][j]]);
            }
        }
        if(z > 1) return 0;
    }
    return 1;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    while(scanf("%d %d", &n, &m) != EOF) {
        rep(i, 1, n) rep(j, 1, m) scanf("%d", a[i]+j);
        int f, x, y;
        fuzhi();
        f = judge();
        if(f) puts("YES");
        else {
            rep(i, 1, m) {
                rep(j, i+1, m) {
                    fuzhi();
                    _swap(i, j);
                    f = judge();
//    printf("i:%d j:%d  f:%d\n", i, j, f);
                    if(f) break;

                }
                if(f) break;
            }
            if(f) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
