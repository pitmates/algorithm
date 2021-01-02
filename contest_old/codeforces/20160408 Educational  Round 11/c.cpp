#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
using namespace std;

const int N = 3e5+5;
int a[N];
int b[N], c[N];
int n, k;

void solve(int t) {
    int x, y = 0, z = 0, u, v;
    if(t <= k) {
        cout << n << endl;
        rep(i, 1, n) cout << "1 ";
        return ;
    }
    c[t] = n+1;
    rep(i, 0, t) {
        x = k+i <= t ? k+i : t-1;
        y = c[x] - c[i] + b[c[i]-1];
        if(y > z) {
            z = y;
            u = c[i];
            v = c[x];
        }
    }
    cout << z << endl;
    rep(i, 1, n) {
        if(i >= u && i < v) cout << "1 ";
        else cout << a[i] << ' ';
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    int t = 0;
    a[0] = b[0] = 0;
    rep(i, 1, n) {
        cin >> a[i];
        if(a[i]) b[i] = a[i] + b[i-1];
        else b[i] = 0, c[t++] = i;
    }
    solve(t);
    return 0;
}
