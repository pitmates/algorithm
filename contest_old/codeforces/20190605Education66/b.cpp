//
// coded by zhuangliupeng
//

#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

const ll MAXN = (1LL<<32)-1LL;


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int l; cin >> l;
    string o;
    int num, f = 0;
    ll ans = 0;
    stack<ll > fo;
    while(!fo.empty()) fo.pop();

    for (int i = 0; i < l; ++i) {
        cin >> o;
        if (o == "for") cin >> num;

        if (ans > MAXN) continue;

        if (o == "for") {
            ll tp = 1;
            if (!fo.empty()) tp = fo.top();
            if (tp == -1) fo.push(-1);
            else {
                ll y = num * tp;
                if (y > MAXN) y = -1;
                fo.push(y);
            }
        }
        else if (o == "add") {
            ll tp = 1;
            if (!fo.empty()) tp = fo.top();
            if (tp == -1) ans = MAXN + 1;
            else ans += tp;
        }
        else if (o == "end") {
            fo.pop();
        }

        if (ans > MAXN) {
            f = 1;
        }

    }
    if (f || ans > MAXN) cout << "OVERFLOW!!!" << endl;
    else cout << ans << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

