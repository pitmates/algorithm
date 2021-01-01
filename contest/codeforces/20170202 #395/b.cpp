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
const int N = 2e5+7;

int a[N];
int n;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    int m = n / 2;
    rep(i, 0, m) if(!(i&1)){
    	swap(a[i], a[n-i-1]);
    }
    rep(i, 0, n) cout << a[i] << " ";
    return 0;
}