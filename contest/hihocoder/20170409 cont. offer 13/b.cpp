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
const int N = 255;

ll matrix[N][N];
int n, m;
ll K;

ll query(int x, int y, int u, int v) {
	return matrix[u][v] - matrix[x-1][v] - matrix[u][y-1] + matrix[x-1][y-1];
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> K;
	zero(matrix);
	rep(i, 1, 1+n) rep(j, 1, 1+m) cin >> matrix[i][j];
	rep(i, 1, 1+n) rep(j, 1, 1+m) {
		matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
	}
	int mx = 0;
	rep(i, 1, 1+n) rep(j, 1, 1+m) rep(k, i, 1+n) {
		int l = j, r = m, md;
		while(l <= r) {
			md = (l + r) >> 1;
			if(query(i, j, k, md) <= K) l = md + 1;
			else r = md - 1;
		}
		if(r < j) continue;
//printf("i:%d j:%d k:%d r:%d  num:%d  %I64d\n", i, j, k, r, (k-i+1) * (r-j+1), query(i, j, k, r));
		mx = max(mx, (k-i+1) * (r-j+1));
	}
	cout << mx << endl;
	return 0;

}
/**
3 3 9
3 4 5
3 1 2   
4 2 3   

 */