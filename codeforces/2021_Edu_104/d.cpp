#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const int N = 1e9+1;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    int T; cin >> T;
    vector<ll> res;
    for (int i = 3; ; i += 2) {
        ll c = (1LL * i * i + 1) / 2;
        if (c < N) res.emplace_back(c);
        else break;
    }

    while (T--) {
        int n;
        cin >> n;
        int id = upper_bound(res.begin(), res.end(), n*1LL) - res.begin();
        cout << id << endl;
    }

    return 0;
}
