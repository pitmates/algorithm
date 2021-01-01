#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const ll MOD = (ll)1e9+7;
const int N = 103;

ll f[N][2];
ll bin[N];
int n;

void init() {
    bin[0] = 1;
    rep(i, 1, N) bin[i] = (bin[i-1] << 1) % MOD;
    return ;
}

ll dfs(int i, int s, bool e) {
    if(i == -1) return 1;
    if(~f[i][s] && !e) return f[i][s];
    ll res = 0;
    rep(d, 0, 2) {
        if(s && d == 1) continue;
        res = (res + dfs(i-1, d==1, e&&(d==1))) % MOD;
    }
    return e ? res : f[i][s] = res;
}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    init();
    cin >> n;
    memset(f, -1, sizeof f);
    cout << (bin[n] - dfs(n-1, 0, 1) + MOD) % MOD << endl;
    return 0;
}
