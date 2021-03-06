//
// Created by pitmates on 2017/12/28.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

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
const int N = 1503;

int v[N];
int n, m;

int fk(int x, int y) {
    if (x == y) return 0;
    return ((y-x) * (y-x+1) / 2) % 2;
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", v+i);
    int res = 0;
    rep (i, 0, n) rep(j, i+1, n) {
            if (v[i] > v[j]) ++res;
    }
    res = res & 1;
    scanf("%d", &m);
    while(m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(fk(a, b) == 1) res ^= 1;

        if (res) puts("odd");
        else puts("even");
    }

#ifdef PIT
    flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
