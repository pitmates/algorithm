#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        int dist = n + m - 2;
        int left = y - d;
        int right = y + d;
        int up = x - d;
        int down = x + d;
        if (left <= 1 && up <= 1) 
            dist = -1;
        if (left <= 1 && right >= m)
            dist = -1;
        if (up <= 1 && down >= n)
            dist = -1;
        if (down >= n && right >= m)
            dist = -1;
        cout << dist << endl;
    }

    return 0;
}