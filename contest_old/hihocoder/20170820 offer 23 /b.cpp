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
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 2500000;

string inp;
struct Node {
    string key;
    vector<int > sons;
} tr[N];

int tot = 0;
string s;

void ins(int rt, int l)
{
    int r = l+1, le = sz(s);
    while (r != le && s[r] != '/') r++;
    if (r==le) return;
    string dir = s.substr(l+1, r-l-1);
//    cout<<dir<<"\n";
    int f = 0;
    for (int x : tr[rt].sons) {
        if (tr[x].key == dir) {
            ins(x, r);
            f = 1;
        }
    }
    if (!f) {
        tr[rt].sons.push_back(++tot);
        tr[tot].key = dir;
        ins(tot, r);
    }
}

vector<string > vs;

void dfs(int u, string s) {
    if(tr[u].sons.size() == 0) {
        string tmp = "/" + tr[u].key;
        vs.pb( s+tmp); 
        return ;
    }
    if(sz(tr[u].sons) == 1) {
        string tmp = "-" + tr[u].key;
        dfs(tr[u].sons[0], s+tmp);
    }
    else {
        string tmp = "/" + tr[u].key;
        for(auto & v : tr[u].sons) {
            dfs(v, s+tmp);
        }
    }
}

int main()
{
#ifdef PIT
//freopen("b.in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> s;
        s += '/';
        ins(0, 0);
    }

    dfs(0, "");
    for(auto& ss : vs) {
        string tp = ss.substr(2, ss.size()-1);
        tp = "/"+tp;
        cout << tp << endl;
    }
    //printf("%d\n", tot);

    
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*
3
/hihocoder/offer23/solutions/p1
/hihocoder/challenge30/p1/test
/game/moba/dota2/uninstall

 */

