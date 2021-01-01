#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (int)j; i <= (int) k; ++i)
using namespace std;
const int N = 100100;
int n, m, q;
bool f[N];

vector<int > v[N];

void dfs(int o, int ft) {
    if(f[o]) {q = 1; return ;}
    f[o] = 1;
    for(int i = 0; i < v[o].size(); ++i) {
        if(v[o][i] == ft) continue;
        dfs(v[o][i], o);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int x, y, s = 0;
    rep(i, 1, m) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    rep(i, 1, n) if(!f[i]) {
            q = 0;
            dfs(i, 0);
            s += !q;
        }
    printf("%d\n", s);
    return 0;
}
