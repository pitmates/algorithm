#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#define mp make_pair

using namespace std;

typedef pair<int, int > P;

bool maze[6][6];
int par[6][6];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
stack<P > v;

void bfs() {
    queue<P > q;
    q.push(mp(0, 0));
    par[0][0] = -2;
    while(!q.empty()) {
        P p = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int x = dx[i] + p.first, y = dy[i] + p.second;
            if(x < 0 || x > 4 || y < 0 || y > 4 || maze[x][y] || par[x][y] != -1) continue;
            q.push(mp(x, y));
            par[x][y] = p.first * 5 + p.second;
        }
    }
    return ;
}

void solve() {
    bfs();
    while(!v.empty()) v.pop();
    v.push(mp(4, 4));
    while(true) {
        P p = v.top();
        int z = par[p.first][p.second];
        if(z == -2) break;
        int x = z / 5, y = z % 5;
        v.push(mp(x, y));
    }
    while(!v.empty()) {
        P p = v.top();
        printf("(%d, %d)\n", p.first, p.second);
        v.pop();
    }
    return ;
}

int main()
{
    for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 5; ++j) {
        scanf("%d", maze[i] + j);
        par[i][j] = -1;
    }
    solve();
    return 0;
}
