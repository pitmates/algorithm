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

    string a, b;
    cin >> a >> b;
    int la = a.size(), lb = b.size();
    vector<int > pre(la+1, 0);
    pre[1] = a[0] == '1';
    for (int i = 1; i < la; ++i) {
        pre[i+1] = pre[i-1] + (a[i] == '1');
    }

    int res = 0;
    for (int i = 0; i < lb; ++i) {
        int one = pre[la-lb+i] - pre[i], ans = la-lb;
        if (b[i] == '1') ans = ans - one;
        res += !(ans & 1);
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
