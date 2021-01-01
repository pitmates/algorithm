#include <bits/stdc++.h>
using namespace std;
const int N = 1027;
int dp[2][N];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int T; cin >> T;
    while(T--) {
        cin >> n >> m;
        memset(dp, -1, sizeof dp);
        dp[0][0] = 0;
        int f = 0;
        for(int i = 1; i <= n; ++i) {
            int v, d, x, s = 0;
            cin >> v >> d;
            while(d--) {
                cin >> x;
                s |= 1 << (x-1);
            }
            for(int j = 0; j < (1<<m); ++j) if(~dp[f][j]){
                dp[f^1][j^s] = max(dp[f][j] + v, dp[f^1][j^s]);
                dp[f^1][j] = max(dp[f^1][j], dp[f][j]);
            }
            f ^= 1;
        }
        cout << dp[f][(1<<m)-1] << endl;
    }
    return 0;
}