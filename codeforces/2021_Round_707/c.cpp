#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
const int N = 5e6+8;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pii> a(n+1, {0, 0});
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort (a.begin(), a.end());
    vector<pair<pii, pii>> vip(N, {{-1, -1}, {-1, -1}});
    pair<pii, pii> res = {{-1, -1}, {-1, -1}};
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            int d = a[i].first + a[j].first;
            auto& z = vip[d];
            if (z.first.first == -1) {
                z.first = {i, j};
            }
            else {
                if (i == z.first.second || i == z.first.first) continue;
                if (j == z.first.second || j == z.first.first) continue;
                z.second = {i, j};
                res = z;
                break;
            }
        }
    }
    if (res.first.first == -1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        auto x = res.first, y = res.second;
        cout << a[x.second].second << " " << a[x.first].second << " ";
        cout << a[y.second].second << " " << a[y.first].second << endl;
    }



    return 0;
}
