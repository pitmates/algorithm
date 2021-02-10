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

int n;


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    /*
    map<int, vector<int > > mv;
    mv.clear();

    mv[2].pb(2);
    mv[3].pb(3);
    for (int i = 3; i < n; ++i) {
        int x = i;
        for (int j = 2; j <= x; ++j) {
            if (x % j == 0) {
                mv[i].pb(j);
                while(x % j == 0) x /= j;
            }
        }
    }
    */

    vector<int > ans(n+3, 0);
    int t = 1;
    for (int i = 2; i <= n; ++i) {
        if (ans[i] != 0) continue;
        for (int j = i; j <= n; j += i) if (!ans[j]){
            ans[j] = t;
        }
        ++t;
    }

    for (int i = 2; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;




#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
