#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

pii query (int x, int y, int z) {
    cout << x << " " << y << " " << z << endl;
    int u, v = x;
    cin >> u;
    if (x == u) v = y;
    return {u, v}; 
}

void search(vector<int>& a, vector<int> b, int n, int p, int st, int f) {
    int m = b.size();
    if (m == 1) {
        a[b[0]] = st-1*f;
        return ;
    }
    if (m == 2) {
        pii z = query(b[0], b[1], p);
        a[z.first] = st - 1*f;
        a[z.second] = st - 2*f;
        return ;
    }
    if (m == 3) {
        pii z = query(b[0], b[1], b[2]);
        a[z.first] = st - 2*f;
        a[z.second] = st - 3*f;
        for (int i = 0; i < 3; ++i) {
            if (b[i] != z.first && b[i] != z.second) {
                a[b[i]] = st - 1*f;
                break;
            }
        }
        return ;
    }
    pii z = query(b[0], b[1], b[2]);
    vector<int> bs, bl;
    for (int i = 0; i < 3; ++i) {
        if (b[i] != z.first && b[i] != z.second) {
            bl.emplace_back(b[i]);
            break;
        }
    }
    bs.emplace_back(z.second);
    for (int i = 3; i < b.size(); ++i) {
        pii w = query(z.first, z.second, b[i]);
        if (z.first == w.first) {
            bl.emplace_back(b[i]);
        }
        else bs.emplace_back(b[i]);
    }
    int ns = bl.size(), ng = bs.size();
    a[z.first] = st + ns;
    search(a, bs, ns, z.first, st+ns, 1);
    search(a, bl, ng, z.first, st+ns, -1);
}



int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int icase = 1; icase <= T; ++icase) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1, 0);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) b[i] = i+1;
        search(a, b, n, 0, 1, 1);
        cout << a[1];
        for (int i = 2; i < n; ++i) cout << " " << a[i]; cout << endl;
        int p;
        cin >> p;
    }

    return 0;
}
