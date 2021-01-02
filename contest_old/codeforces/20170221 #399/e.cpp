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
const int N = 100;
/**
map<pair<int, ll >, int > sg;

int csg(int x, ll msk) {
	msk &= (1ll << (x+1)) - 1;
	pair<int, ll > z = {x, msk};
	if(sg.find(z) != sg.end()) return sg[z];
	ll r = 0;
	for(int i = 1; i <= x; ++i) if((msk&(1ll<<i)) == 0){
		r |= 1ll << csg(x-i, msk|(1ll<<i));
	}
	int e = 0;
	while(r&(1ll<<e)) ++e;
	sg[z] = e;
	return e;
}
**/
int f[N], t = 0;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	/**
	for(int i = 0; i < 61; ++i) {
		printf("i:%d\tsg[i]:%d\n", i, csg(i, 0));
	}
	**/
	for(int i = 0; t < 61; ++i) 
		for(int j = 0; j <= i; ++j){
			f[t++] = i;
		}
	int n, s, g = 0;
	cin >> n;
	while(n--) {
		cin >> s;
		g ^= f[s];
	}
	if(g) cout << "NO";
	else cout << "YES";
	return 0;
}
