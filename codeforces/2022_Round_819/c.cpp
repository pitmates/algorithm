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
        string br;
        cin >> br;
        vector<vector<int>> dep(n+n+1);
        stack<int> si;
        si.push(0);
        int x = 1;
        for (int i = 1; i < n+n; ++i) {
            if (br[i] == '(') {
                x ++;
                si.push(i);
            }
            else {
                int t = si.top();
                si.pop();
                if (si.empty()) {
                    dep[n+n].push_back(t);
                }
                else {
                    int nt = si.top();
                    dep[nt].push_back(t);
                }
                x--;
            }
        }
  
        int res = 0;
        for (int i = 0; i < n+n+1; ++i) if (dep[i].size() > 0) ++res;
        cout << res << endl;
    }


    return 0;
}