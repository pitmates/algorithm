#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second

using namespace std;

const int N = 1e5+5;
pii p[N];
multiset<int > s;
int n;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    rep(i, 0, n) cin >> p[i].fi >> p[i].se;
    sort(p, p+n);
    s.clear();
    s.insert(p[0].se);
    multiset<int >::iterator it;
    rep(i, 1, n) {
        it = s.begin();
        if((*it) <= p[i].fi) s.erase(it);
        s.insert(p[i].se);
    }
    cout << s.size() << endl;
    return 0;
}

