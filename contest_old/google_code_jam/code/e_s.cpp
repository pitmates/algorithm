//
// Created by pitmates on 2020/4/4.
//

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

vector<vector<int > > p;

int n, k;
int flag;
vector<vector<int > > ans;
int row[6][6], col[6][6];

void dfs(int d, int pre, int sum, vector<int > now) {
    if (d == n && sum == k) {
        p.push_back(now);
        return;
    }
    for (int i = pre; i <= n; ++i) {
        if (sum + i > k) break;
        now.push_back(i);
        dfs(d+1, i, sum+i, now);
        now.pop_back();
    }
}

void search(int d, int c) {
    if (d == n-1 && c == n-1) {
        flag = 1;
        return;
    }
//    cout << d << " " << c << endl;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n-1; ++j) {
//            cout << ans[i][j] << " ";
//        }
//        cout << ans[i][n-1] << endl;
//    }
if (d < 2) {
    cout << d << " " << c << endl;
    for (int i = 0; i < n; ++i) cout << ans[0][i] << " "; cout << endl;
    for (int i = 0; i < n; ++i) cout << ans[1][i] << " "; cout << endl << " ";
    for (int i = 0; i <= n; ++i) cout << row[0][i] << " "; cout << endl << "  ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j)
            cout << col[i][j] << " "; cout << endl << "  ";
    }
}
    for (int i = c; i < n; ++i) {
        if (i == d) continue;
        for (int j = 1; j <= n; ++j) {
            if (row[d][j]) continue;
            if (col[i][j]) continue;
            row[d][j] = col[i][j] = 1;
            ans[d][i] = j;
            if (i == n-1) search(d+1, 0);
            else search(d, i+1);
            row[d][j] = col[i][j] = 0;
            ans[d][i] = 0;
        }
    }

}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
        //cout << "Case #" << ic << ":" << endl;
        cin >> n >> k;
        if (k == n + 1 || k == n * n - 1) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<int > q;
        p.clear(); q.clear();
        dfs(0, 1, 0, q);
        flag = 0;
        for (auto vc : p) {
            if (vc[0] == vc[n-2] && vc[n-1] > vc[0]) continue;
            for (int i = 0; i < n; ++i) cout << vc[i] << " "; cout << endl;
            ans = vector<vector<int > >(n, vector<int >(n, 0));
            zero(row);
            zero(col);
            for (int i = 0; i < n; ++i) {
                ans[i][i] = vc[i];
                row[i][ans[i][i]] = 1;
                col[i][ans[i][i]] = 1;
            }
            search(0, 0);
            break;
        }
        if (flag == 0) cout << "IMPOSSIBLE" << endl;
        else {
            cout << "POSSIBLE" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n-1; ++j) {
                    cout << ans[i][j] << " ";
                }
                cout << ans[i][n-1] << endl;
            }
        }

    }
#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
