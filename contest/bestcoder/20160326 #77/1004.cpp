#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int o = 1e6;
const int N = 2020;

int a[N], v[N];
double dp[N];
int n, m;

void solve() {
    for(int i = 1; i <= n; ++i)
        for(int j = i, f = 0; j; --j) {
            if(v[j]) ++f;
            if(f > 1) break;
            if(f) dp[i] = fmax(dp[i], dp[j-1]+log2(i-j+1));
        }
    printf("%.0f\n", floor(o*dp[n]));
    return ;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; ++i) dp[i] = 0.0, v[i] = 0;
        for(int i = 1; i <= m; ++i) scanf("%d", a+i), v[++a[i]] = 1;
        sort(a+1, a+m+1);
        solve();
    }
    return 0;
}

