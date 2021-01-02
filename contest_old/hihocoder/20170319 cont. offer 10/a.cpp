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
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int n = sz(s);
		int L = 0, A = 0;
		int f = 1;
		rep(i, 0, n) {
			if(s[i] == 'A') {
				L = 0; A++;
				if(A > 1) {
					f = 0;
					break;
				}
			}
			else if(s[i] == 'L') {
				L++;
				if(L > 2) {
					f = 0;
					break;
				}
			}
			else L = 0;
		}
		if(f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	return 0;
}
