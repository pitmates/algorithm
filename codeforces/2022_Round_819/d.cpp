#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

vector<int> f;

int f_f(int x) {
    return f[x] == x ? x : f[x] = f_f(f[x]);
}

void merge_f(int x, int y) {
    f[y] = x;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        f.resize(n+1);
        for (int i = 0; i <= n; ++i) f[i] = i;
        vector<int> u(m), v(m), b(m, 0);
        set<int> eg;
        int w;
        for (int i = 0; i < m; ++i) {
            cin >> u[i] >> v[i];
            int fu = f_f(u[i]);
            int fv = f_f(v[i]);
            if (fv == fu) {
                b[i] = 1;
                eg.insert(u[i]);
                eg.insert(v[i]);
                w = i;
            }
            else f[fv] = fu;
        }

        if (m - n == 2 && eg.size() == 3) {
            for (int i = 0; i <= n; ++i) f[i] = i;
            f[f_f(u[w])] = f[f_f(v[w])];
            for (int i = 0; i < m; ++i) if(!b[i]) {
                int fu = f_f(u[i]);
                int fv = f_f(v[i]);
                if (fu == fv) b[i] = 1;
                else f[fu] = fv;
            }
            b[w] = 0;
        }

        for (int i = 0; i < m; ++i) cout << b[i]; cout << endl;

    }

    return 0;
}