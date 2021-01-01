#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
using namespace std;

const int N = 24*60;

int a, ta, b, tb;
int h, m;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);

    scanf("%d %d %d %d", &a, &ta, &b, &tb);
    scanf("%d:%d", &h, &m);
    int ts = h * 60 + m, te = ts + ta;
    if(te > N) te = N;
    int ans = 0;
    for(int i = 5*60; i < te; i += b)
        if(i+tb > ts && i < te) ++ans;

    printf("%d\n", ans);

    return 0;
}
