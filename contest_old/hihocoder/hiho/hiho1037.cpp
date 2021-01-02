#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j; i < (int)k; ++i)
using namespace std;
const int N = 101;
int n;
int a[N][N];
int dp[2][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    rep(i,0,n) rep(j,0,i+1) cin >> a[i][j];
    int f = 0;
    dp[0][0] = a[0][0];
    rep(i,1,n) {
        dp[f^1][0] = dp[f][0] + a[i][0];
        dp[f^1][i] = dp[f][i-1] + a[i][i];
        rep(j,1,i) {
            dp[f^1][j] = max(dp[f][j-1], dp[f][j]) + a[i][j];
        }
        f ^= 1;
    }
    int maxv = 0;
    rep(i,0,n+1) maxv = max(maxv, dp[f][i]);
    cout << maxv << endl;
    return 0;
}
