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
const int N = 3e5+7;

int a, b, c;
ll usb[N], ps[N];
int u, p, m;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b >> c;
    u = p = 0;
    ll x;
    string s;
    cin >> m;
    rep(i, 0, m) {
    	cin >> x >> s;
    	if(s[0] == 'U') usb[u++] = x;
    	else ps[p++] = x;
    }
    sort(usb, usb+u);
    sort(ps, ps+p);
    for(int i = 1; i < u; ++i) usb[i] = usb[i] + usb[i-1];
    for(int i = 1; i < p; ++i) ps[i] = ps[i] + ps[i-1];
    if(a > u) {
    	if(b > p) {
    		cout << u+p << " " << usb[u-1] + ps[p-1];
    	}
    	else {
    		if(b+c > p) cout <<  u+p << " " << usb[u-1] + ps[p-1];
    		else cout <<  u+b+c << " " << usb[u-1] + ps[b+c-1];
    	}
    }
    else {
    	if(b > p) {
    		if(a+c > u) cout <<  u+p << " " << usb[u-1]+ps[p-1];
    		else cout <<  a+c+p << " " << usb[a+c-1]+ps[p-1];
    	}
    	else {
    		if(a+b+c > u+p) cout <<  u+p << " " << usb[u-1]+ps[p-1];
    		else {
    			int mi = min(a+c, u), z = a+b+c, i, j = z-mi;
    			ll mx = usb[mi-1] + ps[j-1], ans;	
    			for( i = mi-1; i >= a; --i) {
    				++j;
    				if(j > p) break;
    				ans = usb[i-1] + ps[j-1];
    				if(ans < mx) mx = ans;
    			
    			}
    			cout << a+b+c << " " << mx;
    		}
    	}
    }
    return 0;
}
/**
2 1 1
10
5 USB
6 USB
7 USB
8 USB
10 USB
6 PS/2
3 PS/2
7 PS/2
2 PS/2
13 PS/2

 */