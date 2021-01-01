#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;

const int N = 105;
int n, k;
string s[N];
string aim;

inline bool cmp(string i, string j) { return SZ(i) < SZ(j); }

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    rep(i, 1, n+1) cin >> s[i];
    cin >> aim;
    sort(s+1, s+n+1, cmp);
    s[0] = "";
    s[n+1] = s[n]+s[n];
    int minv, maxv, ans = 0;
    rep(i, 1, n+2) {
        ++ans;
        if(SZ(s[i]) > SZ(s[i-1]) && SZ(s[i]) == SZ(aim)) minv = ans;
        if(SZ(s[i+1]) > SZ(aim) && SZ(s[i]) == SZ(aim)) maxv = ans;
        if(i % k == 0) ans += 5;
    }
    cout << minv << " " << maxv << endl;
    return 0;
}
