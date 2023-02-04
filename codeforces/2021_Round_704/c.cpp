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

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> R(m);
    int r = n-1;
    for (int i = m-1; i >= 0; --i) {
        while (r >= 0 && s[r] != t[i]) --r;
        R[i] = r--;
    }
    int l = 0, res = 0;
    for (int i = 0; i < m-1; ++i) {
        while (l < n && s[l] != t[i]) ++l;
        res = max(res, R[i+1]-l);
        l++;
    }
    cout << res << endl;
    


    return 0;
}
