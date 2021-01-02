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
const int N = 1003;

int n;
int A[N];


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> A[i];
	sort(A, A+n);
	ll ans = 0;
	rep(i, 0, n) rep(j, i+1, n) {
		int s = A[i] + A[j];
		rep(k, 0, n) if(k != i && k != j) {
			int sub = s - A[k];
			int kx = lower_bound(A, A+n, sub) - A;
			int ky = upper_bound(A, A+n, sub) - A;
	//printf("i:%d j:%d k:%d s:%d sub:%d kx:%d ky:%d\n", i, j, k, s, sub, kx, ky);
			int kz = ky - kx;
			if(i >= kx && i < ky) --kz;
			if(j >= kx && j < ky) --kz;
			ans += max(kz, 0);
		}
	}
	cout << ans << endl;
	return 0;
}
