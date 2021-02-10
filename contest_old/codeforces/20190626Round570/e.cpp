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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    queue<string > qs;
    while(!qs.empty()) qs.pop();

    map<string, int > mmp;
    mmp.clear();

    qs.push(s);
    mmp[s] = 1;
    int ans = 0;
    while(!qs.empty()) {
        string f = qs.front();
        qs.pop();
//        cout << k << "  " << f << endl;
        --k;
        ans += n - f.size();
        if (k == 0) break;
        for (int i = 0; i < f.size(); ++i) {
            string tmp = f;
            tmp.erase(tmp.begin()+i);
            if (mmp[tmp]) continue;
            qs.push(tmp);
            mmp[tmp] = 1;
        }
    }
    if (k) cout << -1 << endl;
    else cout << ans << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
