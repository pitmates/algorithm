#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 32;
ll b[N];
int n;

inline void init() {
    b[0] = 1;
    rep(i, 1, N) b[i] = (b[i-1] << 1);
    return ;
}

int f[N];

int dfs(int i, int v) {
    if(i == -1) return v == n;
    if( v + 2*b[i] + b[i+1] < n) return 0;
    int ans = 0;
    for(int d = 0; d < 3; ++d) {
        if(v + d * b[i] > n) break;
        ans += dfs(i-1, v+d*b[i]);
    }
    return ans;
}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    init();
    cin >> n;
    memset(f, -1, sizeof f);
    int s = dfs(30, 0);
    cout << s;
    return 0;
}
