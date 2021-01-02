#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define inf 0x3f3f3f3f
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 0;
    for(auto i : s) {
        if(i == 'A') ++ans;
    }
    if(ans > SZ(s)-ans) cout << "Anton";
    else if(ans < SZ(s)-ans) cout << "Danik";
    else cout << "Friendship";
    return 0;
}
