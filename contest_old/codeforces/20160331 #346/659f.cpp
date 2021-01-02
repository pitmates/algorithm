#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 1010;
int mat[N][N];
bool used[N][N], g[N][N];
int n, m;
ll k;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


bool dfs(int i, int j, int cst, ll &cnt) {
    if(i < 0 || i >= n || j < 0 || j >= m || mat[i][j] < cst || used[i][j]) return false;
    used[i][j] = true;
    --cnt;
    if(mat[i][j] == cst) g[i][j] = true;
//printf("-- %d %d %d %d\n", i, j, cnt, cst);
    rep(ii, 0, 4) {
        int x = i+dx[ii], y = j+dy[ii];
        if(!cnt || dfs(x, y, cst, cnt)) return true;
    }
    return false;
}

void solve() {
    memset(g, false, sizeof g);
    rep(i, 0, n) rep(j, 0, m) {
            if(g[i][j] || k % mat[i][j]) continue;
            ll v = k / mat[i][j], u = v;
            if(v > 1LL*n*m) continue;
            memset(used, false, sizeof used);
//printf("%d %d %d %d\n", i, j, mat[i][j], (int)v);
            if(dfs(i, j, mat[i][j], v)) {
                puts("YES");
                ll t = 0;
                rep(ii, 0, n) {
                    rep(jj, 0, m) {
                        if(used[ii][jj] && t < u) printf("%d ", mat[i][j]);
                        else printf("0 ");
                    }
                    puts("");
                }
                return ;
            }
        }
    puts("NO");
    return ;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT

    scanf("%d %d %I64d", &n, &m, &k);
    rep(i, 0, n) rep(j, 0, m) scanf("%d", mat[i]+j);
    solve();
    return 0;
}
