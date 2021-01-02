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
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll > vk;
    vk.clear();
    vk.pb(1); vk.pb(n);
    for(ll i = 2; i * i <= n; ++i) {
    	if(n % i == 0) {
    		vk.pb(i);
    		if(i * i < n) vk.pb(n/i);
    	}
    }
    if(vk.size() < k) cout << -1;
    else {
    	sort(vk.begin(), vk.end());
    	cout << vk[k-1];
    }
    return 0;
}