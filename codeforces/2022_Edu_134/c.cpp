#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<int> minRes(n);
        vector<int> maxRes(n);

        for (int i = 0; i < n; ++i) {
            minRes[i] = (*lower_bound(b.begin(), b.end(), a[i])) - a[i];
        }
        
        stack<int> res;
        int mx = 0;
        for (int i = n - 1, y = n-1; i >= 0; --i) {
            int x = a[i];
            while (y >= 0 && b[y] >= x) {
                res.push(b[y]);
                mx = max(mx, b[y]);
                y--;
            }

            maxRes[i] = mx - a[i];
            res.pop();
            if (res.empty()){
                mx = 0;
            }
        }

        for (auto x : minRes)
            cout << x << " ";
        cout << endl;

        for (auto x : maxRes)
            cout << x << " ";
        cout << endl;
        
    }


    return 0;
}