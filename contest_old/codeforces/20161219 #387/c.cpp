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
const int N = 110;
int vis[N];

struct Node {
	vector<int > id;
	int ed, st;
	int siz, ans;
	int in(int s, int k, int e, int n) {
		st = s; ed = s + e - 1; siz = k; ans = 0;
		int x = 0;
		for(int i = 1; i <= n; ++i) if(!vis[i]) ++x;
		if(x < k) return 0;
		id.clear();
		for(int i = 1, t = 0; i <= n && t < siz; ++i) if(!vis[i]) {
			id.pb(i); vis[i] = 1; ++t; ans += i;
		}
		return 1;
	}
	void out() {
		rep(i, 0, siz) {
			vis[id[i]] = 0;
		}
		id.clear();
		siz = 0;
	}
	void prf() {
		printf("st:%d  ed:%d  siz:%d \n", st, ed, siz);
		for(int i = 0; i < siz; ++i) printf("%d ", id[i]); puts("");
	}
};

bool cmp(Node a, Node b) {
	return a.ed < b.ed;
}

int n, q;
int s, k, e;

vector<Node > v;

int binse(int x) {
	int l = 0, r = sz(v), mid;
	while(l + 1 <= r) {
		mid = (l + r) >> 1;
		if(v[mid].ed >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}


int z[] = {1, 2, 3, 3 , 4, 5, 6, 7, 9};
int binsea(int x) {
	int l = 0, r = 9, mid;
	while(l + 1 <= r) {
		mid = (l + r) >> 1;
		if(z[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}



int main()
{
//freopen("c.in", "r", stdin);
//freopen(".out", "w", stdout);
//rep(i, 0, 10) printf("i:%d  %d\n", i, binsea(i));
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	zero(vis); v.clear();
	for(int p = 0; p < q; ++p) {
		cin >> s >> k >> e;
	//printf("s:%d  k:%d  e:%d\n", s, k, e);
		if(!v.empty()){
			int d = binse(s) - 1;
		//printf("d == %d\n", d);
			if(d >= 0){
				for(int i = 0; i <= d; ++i) {
					v[i].out();
				}
				v.erase(v.begin(), v.begin()+d);
			}
		}
//for(int i = 1; i <= n; ++i) printf("%d ", vis[i]); puts("");
		Node nd; 
		int flag = nd.in(s, k, e, n);
		if(flag == 0) {
			cout << "-1" << endl;
			continue;
		}
		if(!v.empty()) {
			
			int d = binse(nd.ed);
			v.insert(v.begin()+d, nd);
		}
		else v.pb(nd);
/*
puts("====== v ======");
for(int i = 0; i < sz(v); ++i) v[i].prf();
*/
		cout << nd.ans << endl;
	}
	return 0;
}
