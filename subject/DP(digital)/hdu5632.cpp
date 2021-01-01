#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
const int MOD = 998244353;

inline int add(int x, int y) {
    x = x + y;
    if(x > MOD) x -= MOD;
    return x;
}

int dg[N];
int f[N][N][2];
char c[N];


int solve()

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", c);
        printf("%d\n", solve());
    }
    return 0;
}
