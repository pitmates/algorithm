#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


bool cmp (const pll& a, const pll& b) {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int main()
{
// freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int  n;
        ll A, H;
        cin >> A >> H >> n;
       
        vector<ll> a(n), h(n);
        vector<pll> at(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            ll t = (h[i] + A - 1) / A;
            ll cost = 1LL * t * a[i]; 
            at[i] = {a[i], cost};
        }
        sort (at.begin(), at.end(), cmp);

        int f = 1;
        for (int i = 0; i < n; ++i) {
            H -= at[i].second;
            if (H < -((ll)1e9+7)) break;
        }

        ll ai = at[n-1].first;
        if (H > -ai) cout << "YES" << endl;
        else  cout << "NO" << endl;

    }

    return 0;
}
