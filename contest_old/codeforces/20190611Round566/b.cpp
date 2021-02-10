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
const int N = 512;

string S[N];
int x, y;


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> x >> y;
    int stars = 0;
    for (int i = 0; i < x; ++i) {
        cin >> S[i];
        for (int j = 0; j < y; ++j) {
            if (S[i][j] == '*') ++stars;
        }
    }

    int u = -1, v = -1;
    rep(i, 1, x-1) rep(j, 1, y-1) {
        if (S[i][j] == '*' && S[i+1][j] == '*' && S[i-1][j] == '*' \
            && S[i][j-1] == '*' && S[i][j+1] == '*') {
            u = i; v = j;
            break;
        }
    }

    if (u == -1) {
        cout << "NO" << endl;
        return 0;
    }
    int cnt = 1;
    //up
    for (int i = u-1; i >= 0; --i) {
        if (S[i][v] == '*') ++cnt;
        else break;
    }
    //down
    for (int i = u+1; i < x; ++i) {
        if (S[i][v] == '*') ++cnt;
        else break;
    }
    //left
    for (int j = v-1; j >= 0; --j) {
        if (S[u][j] == '*') ++cnt;
        else break;
    }
    //right
    for (int j = v+1; j < y; ++j) {
        if (S[u][j] == '*') ++cnt;
        else break;
    }

    if (cnt != stars) cout << "NO" << endl;
    else cout << "YES" << endl;



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
