#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 200200;
int n;
int p[N], z[N];
int root, w, y;

void findset(int x) {
    z[x] = ++y;
    while(!z[p[x]]) x = p[x], z[x] = y;
    if(z[p[x]] == y) {
        if(!root) root = x;
        if(p[x] != root) p[x] = root, ++w;
    }
    return ;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT

    root = w = y = 0;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", p+i);
    memset(z, 0, sizeof z);
    rep(i, 1, n) if(p[i] == i) root = i;
    rep(i, 1, n) if(!z[i]) findset(i);
    printf("%d\n", w);
    rep(i, 1, n) printf("%d%c", p[i], (i==n) ? '\n' : ' ');
    return 0;
}
