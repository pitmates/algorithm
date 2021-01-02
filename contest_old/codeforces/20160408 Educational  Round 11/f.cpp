#include <bits/stdc++.h>

#define ll long long
#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define mp make_pair

using namespace std;

const int N = 2e5+3;

int a[N];
ll sum[N];
int n, t;
int idx[N];
ll dp[N];

void solve() {

}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    sum[0] = dp[1] = 0;
    rep(i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        dp[1] += 1LL * i * a[i];
    }
    solve();
    return 0;
}
