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
const int N = 300003;

ll arr[N];
int n, q;

struct Segment_Tree {
	struct Tree{
		int pre, suf, ans;
	}tree[N<<2];

	void pushUP(int l, int r, int rt) {
		tree[rt].pre = tree[rt<<1].pre; tree[rt].suf = tree[rt<<1|1].suf;
		tree[rt].ans = max(tree[rt<<1].ans, tree[rt<<1|1].ans);
		int m = (l + r) >> 1;
		if(!arr[m] || !arr[m+1] || (arr[m] < 0 && arr[m+1] > 0)) return ;
		if(tree[rt<<1].pre == m-l+1) tree[rt].pre = tree[rt<<1].pre + tree[rt<<1|1].pre;
		if(tree[rt<<1|1].suf == r-m) tree[rt].suf = tree[rt<<1].suf + tree[rt<<1|1].suf;
		tree[rt].ans = max(tree[rt].ans, tree[rt<<1].suf + tree[rt<<1|1].pre);
	}

	void build(int l, int r, int rt) {
		if(l == r) {
			tree[rt].pre = tree[rt].suf = tree[rt].ans = 1;
			return ;
		}
		int m = (l + r) >> 1;
		build(l, m, rt<<1);
		build(m+1, r, rt<<1|1);
		pushUP(l, r, rt);
	}

	void update(int l, int r, int rt, int pos, int d){
		if(l == r) {
			arr[pos] += d;
			return ;
		}
		int m = (l + r) >> 1;
		if(pos <= m) update(l, m, rt<<1, pos, d);
		else update(m+1, r, rt<<1|1, pos, d);
		pushUP(l, r, rt);

	}

};

Segment_Tree T;

int main()
{
//freopen("739c.in", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	rep(i, 1, n+1) cin >> arr[i];
	rep(i, 1, n) arr[i] = arr[i+1] - arr[i];
	--n;
	cin >> q;
	int l, r, d;
	if(!n) {
		rep(i, 0, q) {
			cin >> l >> r >> d;
			puts("1");
		}
		return 0;
	}
	T.build(1, n, 1);
	rep(i, 0, q){
		cin >> l >> r >> d;
		if(l > 1) T.update(1, n, 1, l-1, d);
		if(r <= n) T.update(1, n, 1, r, -d);
		printf("%d\n", T.tree[1].ans + 1);
	}
	return 0;
}
