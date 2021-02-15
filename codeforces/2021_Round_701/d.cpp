#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
const int LCM = 720720;

int pow4(int x) {
    return x * x * x * x;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i+j & 1) cout << (LCM + pow4(mat[i][j])) << " ";
            else cout << LCM << " ";
        }
        cout << endl;
    }

    return 0;
}
