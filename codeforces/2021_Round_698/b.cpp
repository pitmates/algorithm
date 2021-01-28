#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

bool hasD(int d, int x) {
    while (x) {
        if (x % 10 == d) return true;
        x /= 10;
    }
    return false;
}

bool findD(int d, int x) {
    if (hasD(d, x)) return true;
    vector<int> g(100, 0);
    for (int i = 0; i < 10; ++i) {
        int y = i * 10 + d;
        int z = d * 10 + i;
        g[y] = 1;
        g[z] = 1;
    }
    for (int i = 0; i <= x; ++i) {
        if (g[i] == 0) continue;
        for (int j = i+i; j <= x; j += i) g[j] = 1;
    }
    for (int i = 0; i < x; ++i) {
        if (g[i] == 0) continue;
        int y = x - i;
        if (hasD(d, y)) return true; 
    }
    return false;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int q, d;
        cin >> q >> d;
        while (q--) {
            int x; cin >> x;
            if (x > 99) cout << "YES" << endl;
            else {
                if (hasD(d, x)) cout << "YES" << endl;
                else {
                    if (findD(d, x)) cout << "YES" << endl;
                    else cout << "NO" << endl;
                }
                
            }
        }
    }

    return 0;
}
