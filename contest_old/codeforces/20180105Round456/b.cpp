//
// Created by pitmates on 2018/1/5.
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
    ll k, n;
    cin >> n >> k;
    vector <int > v(100, 0);
    int t = 0;
    ll m = n;
    while(m) {
        v[t++] = m & 1;
        m >>= 1;
    }
    --t;
    int c = t;


    if (k == 1) cout << n << endl;
    else cout << (1LL << (t+1)) - 1 << endl;




#ifdef PIT
    flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
