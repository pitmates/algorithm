#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 1e9+7;
const int N = 1e6+1;
ll n, m;
ll dp[N];
int main()
{
    cin >> n >> m;
    ll x = 1, y = 1;
    for(int i = 1; i <= n; ++i) {
        y = (y * (m+m-1) % M + x) % M;
        x = (x * m) % M;
    }
    cout << y << endl;
    return 0;
}

