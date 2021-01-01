#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
using namespace std;

ll q, P;

ll multi_mod(ll a, ll b, ll M) {
    ll x = 0;
    while(b) {
        if(b&1) x = (x + a) % M;
        a = (a + a) % M;
        b >>= 1;
    }
    return x;
}

void solve() {
    if(q == 2) {
        puts("0");
        return ;
    }
    ll x = multi_mod(q-2, (q-1)/2, P);
    printf("%I64d\n", x);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d %I64d", &q, &P);
        solve();
    }
    return 0;
}
