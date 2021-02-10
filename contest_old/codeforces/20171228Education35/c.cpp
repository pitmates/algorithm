//
// Created by pitmates on 2017/12/28.
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
const int mo = 1e9+7;
const int N = 3;

int a[N];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);


    for (int i = 0; i < 3; ++i) cin >> a[i];
    sort(a, a+3);
    int f = 0;
    if (a[0] == 1) f = 1;
    else if (a[0] == a[1] && a[1] == 2) f = 1;
    else if (a[0] == a[2] && a[2] == 3) f = 1;
    else if (a[0] == 2 && a[1] == 4 && a[2] == 4) f = 1;
    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;

#ifdef PIT
    flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
/*
 * 1 3 5 7 9 11
 * 2 4 6 8 10 12
 */