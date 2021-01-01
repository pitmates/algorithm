#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 3e5+17;
int p[N], foe[N], a[N];
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);

    while(cin >>n >> m) {
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            p[a[i]] = i;
        }
        for(int i = 0, x, y; i < m; ++i) {
            cin >> x >> y;
            if(p[x] > p[y]) foe[x] = max(foe[x], p[y]);
            else foe[y] = max(foe[y], p[x]);
        }
        int x = 1;
        ll s = 0;
        for(int i = 1; i <= n; ++i) {
            x = max(x, foe[a[i]] + 1);
            s += 1 - x + i;
        }
        cout << s << endl;
    }
    return 0;
}
