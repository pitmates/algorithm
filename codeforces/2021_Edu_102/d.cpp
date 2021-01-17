#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

struct Data {
    int mx;
    int mi;
    int now;
    Data(int x=0, int i=0, int w=0): mx(x), mi(i), now(w) {}
    Data operator + (const Data& a) {
        return Data(max(mx, now+a.mx), min(mi, a.mi+now), now+a.now);
    }
};

int main()
{
// freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<Data> pre(n+1, Data(0, 0, 0)), suf(n+1, Data(0, 0, 0));
        for (int i = 0; i < n; ++i) {
            Data now;
            if (s[i] == '+') now = {1, 0, 1};
            else now = {0, -1, -1};
            pre[i+1] = pre[i] + now;
        }
        for (int i = n-1; i >= 0; --i) {
            Data now;
            if (s[i] == '+') now = {1, 0, 1};
            else now = {0, -1, -1};
            suf[i] = now + suf[i+1];
        }
        // for (int i = 0; i < n+1; ++i) {
        //     cout << i << "  " << pre[i].mx << " " << pre[i].mi << " " << pre[i].now << endl;
        // }
        // for (int i = 0; i < n+1; ++i) {
        //     cout << i << "  " << suf[i].mx << " " << suf[i].mi << " " << suf[i].now << endl;
        // }
        while (m--) {
            int x, y;
            cin >> x >> y;
            Data res = pre[x-1] + suf[y];
            cout << (res.mx - res.mi + 1) << endl;
        }
    }

    return 0;
}
