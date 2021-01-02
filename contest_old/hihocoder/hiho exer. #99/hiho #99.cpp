#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
#define pi pair<int, int >
#define fi first
#define se second

using namespace std;
const int N = 10;

pair<int, int > p[3];
int d[3][N][N];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int k) {
    queue<pi > q;
    while(!q.empty()) q.pop();
    q.push(p[k]);
    d[k][p[k].fi][p[k].se] = 0;
    while(!q.empty()) {
        pi z = q.front(); q.pop();
        rep(i, 0, 8) {
            int x = z.fi + dx[i], y = z.se + dy[i];
            if(x > 0 && x < 9 && y > 0 && y < 9 && d[k][x][y] == -1) {
                d[k][x][y] = d[k][z.fi][z.se] + 1;
                q.push(mp(x, y));
            }
        }
    }
}

int main()
{
    int t; char c[2];
    for(scanf("%d", &t); t; --t) {
        memset(d, -1, sizeof d);
        rep(i, 0, 3) {
            scanf("%s", c);
            p[i] = {c[0]-'A'+1, c[1]-'0'};
            bfs(i);
        }
        int m = 1e9;
        rep(i, 1, 9) rep(j, 1, 9){
            int x = 0;
            rep(k, 0, 3) x += d[k][i][j];
            if(m > x) m = x;
        }
        printf("%d\n", m);
    }
    return 0;
}
