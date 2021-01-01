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
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = sz(s);
    int v[30];
    zero(v);
    int t = 1, flag = 1;
    if(s[0] != 'a') {
        cout << "NO";
        return 0;
    }
    rep(i, 1, n) {
        int x = s[i] - 'a';
        if(x > t) {
            flag = 0;
            break;
        }
        if(x == t) ++t;
    }
    if(flag) cout << "YES" ;
    else cout << "NO";

    return 0;
}

