#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

bool cmp(const pair<pii, int>& a, const pair<pii, int>& b) {
    if (a.first.first != b.first.first) {
        return a.first.first < b.first.first;
    }
    return a.first.second < b.first.second;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<pii, int>> r(n);
        for (int i = 0; i < n; ++i) {
            int h, w;
            cin >> h >> w;
            if (h > w) swap(h, w);
            r[i] = {{h, w}, i};
        }
        // r[n] = {{inf, inf}, n};
        sort(r.begin(), r.end(), cmp);

        // for (auto rx : r) cout << rx.first.first << " " << rx.first.second << "   " << rx.second << endl;
        
        int usedId = -1, usedY = 1e9+7, toId = -1, toY = usedY, nowX = r[0].first.first;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (r[i].first.first == nowX) {
                if (r[i].first.second < toY) {
                    toY = r[i].first.second;
                    toId = r[i].second;
                }
                if (r[i].first.second > usedY && usedId != -1) {
                    ans[r[i].second] = usedId + 1;
                }
                else {
                    ans[r[i].second] = -1;
                }
            }
            else {
                if (toY < usedY) {
                    // cout << toY << " " << usedY << "  " << toId << " " << usedId << endl;
                    usedY = toY;
                    usedId = toId;
                }
                nowX = r[i].first.first;
                toId = r[i].second;
                toY = r[i].first.second;
                if (r[i].first.second > usedY && usedId != -1) {
                    ans[r[i].second] = usedId + 1;
                }
                else {
                    ans[r[i].second] = -1;
                }
               
            }
        }
        for (auto x : ans) cout << x << " "; cout << endl;
    }    

    return 0;
}
