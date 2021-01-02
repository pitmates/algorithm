#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 100100;
string s;
int m;
bool vis[N];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> m >> s;
    int n = s.size();
    vector<char > v; v.clear();
    char mx = 'a';
    memset(vis, 0, sizeof vis);
    for(int i = 0; i <= n-m; ++i) {
        int k = i, ri = i+m;
        for(int j = i; j < ri; ++j) {
            if(s[j] <= s[k]) k = j;
        }
        v.push_back(s[k]); mx = max(s[k], mx);
        vis[k] = 1; i = k;
    }
    for(int i = 0; i < n; ++i) if(s[i] < mx && !vis[i]) v.push_back(s[i]);
    sort(v.begin(), v.end());
    for( auto i : v) cout << i; cout << endl;
    return 0;
}
