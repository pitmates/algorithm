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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        map<char, int> mc;
        mc.clear();
        for (auto c : s) mc[c]++;
        int fx = 0, fy = 0;
        if (x > 0) fx = mc['R'];
        else if (x < 0) fx = mc['L'];
        if (y > 0) fy = mc['U'];
        else if (y < 0) fy = mc['D'];
        if (abs(fx) >= abs(x) && abs(fy) >= abs(y)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
