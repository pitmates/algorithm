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

    int T; 
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    ll x, sum[3] = {0, 0, 0}, mv[3] = {INF, INF, INF};
    for (int i = 0; i < n1; ++i) {
        cin >> x;
        sum[0] += x;
        mv[0] = min(mv[0], x);
    }
    for (int i = 0; i < n2; ++i) {
        cin >> x;
        sum[1] += x;
        mv[1] = min(mv[1], x);
    }
    for (int i = 0; i < n3; ++i) {
        cin >> x;
        sum[2] += x;
        mv[2] = min(mv[2], x);
    }

    sort(sum, sum+3);
    sort(mv, mv+3);

    ll res = max(sum[1] + sum[2] - sum[0], sum[1] + sum[2] + sum[0] - (mv[0] + mv[1]) * 2);

    // cout << res << "  " << m << " "  << endl;
    cout << res << endl;


    return 0;
}
