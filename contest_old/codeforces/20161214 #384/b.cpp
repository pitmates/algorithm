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
const int N = 52;

ll b[N];

void init() {
	b[0] = 1;
	for(int i = 1; i < N; ++i) b[i] = (b[i-1]<<1);
	return ;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int n;
    ll k;
    cin >> n >> k;
    while(k && n) {
    	if(k == b[n-1]) {
    		cout << n;
    		break;
    	}
    	if(k > b[n-1]) k -= b[n-1];
    	--n;
    }
    return 0;
}