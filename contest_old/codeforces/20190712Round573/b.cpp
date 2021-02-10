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
    string a, b, c;
    int x, y, z;
    cin >> a >> b >> c;
    x = a[0] - '0', y = b[0] - '0', z = c[0] - '0';

    if (a[1] == b[1]) {
//        cout << "A" << endl;
        if (a[1] == c[1]) {
            if (x > y) swap(x, y);
            if (y > z) swap(y, z);
            if (x > y) swap(x, y);
            if (x == y && y == z) cout << 0 << endl;
            else if (x == y || x == z || y == z) cout << 1 << endl;
            else {
                if (abs(x-y) == 1 && abs(y-z) == 1) cout << 0 << endl;
                else if (abs(x-y) == 1 || abs(y-z) == 1) cout << 1 << endl;
                else if (abs(x-y) == 2 || abs(y-z) == 2) cout << 1 << endl;
                else cout << 2 << endl;
            }
        }
        else {
            if (x == y) cout << 1 << endl;
            else if (abs(x-y) == 1 || abs(x-y) == 2) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    else if (a[1] == c[1]) {
//        cout << "B" << endl;
        if (x == z) cout << 1 << endl;
        else if (abs(x-z) == 1 || abs(x-z) == 2) cout << 1 << endl;
        else cout << 2 << endl;
    }
    else if (b[1] == c[1]) {
//        cout << "C" << endl;
        if (y == z) cout << 1 << endl;
        else if (abs(y-z) == 1 || abs(y-z) == 2) cout << 1 << endl;
        else cout << 2 << endl;
    }

    else cout << 2 << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
