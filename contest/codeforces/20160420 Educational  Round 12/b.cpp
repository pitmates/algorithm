#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
using namespace std;

const int N = 127;

vector<int > v;
int n, k, m;

int main()
{
#ifdef PIT
freopen("b.in", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT

    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    int x, y, z;
    v.clear();
    rep(i, 0, k) cin >> x, v.push_back(x);
    ll s = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> x;
            rep(q, 0, k) if(v[q] == x) {
                s += q+1;
                v.erase(v.begin() + q);
                v.insert(v.begin(), x);
                break;
            }
        }
    }
    cout << s;
    return 0;
}
