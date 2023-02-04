#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


vector<int> solve2(int n, int k) {
    vector<int> ans(k);
    int z = n / 2;
    if (z&1) {
        ans[0] = ans[1] = z-1; ans[2] = 2;
        int y = (k-3) % 4;
        if (y == 0) {
            for (int i = 3; i < k; i += 4) {
                ans[i] = ans[i+1] = ans[i+2] = ans[i+3] = 1;
                ans[0] -= 2;
                ans[1] -= 2;
            }
        }
        else {
            
            for (int i = 3; i < k && i < 5; ++i) {
                ans[0]--; ans[1]--;
                ans[i] = 2;
            }
            for (int i = 5; i < k; i += 4) {
                ans[i] = ans[i+1] = ans[i+2] = ans[i+3] = 1;
                ans[0] -= 2;
                ans[1] -= 2;
            }
        }
    }
    else {
        ans[0] = z; ans[1] = ans[2] = z/2;
        int y = (k-3) % 4;
        if (y == 0) {
            for (int i = 3; i < k; i += 4) {
                ans[i] = ans[i+1] = ans[i+2] = ans[i+3] = 1;
                ans[0] -= 2;
                ans[1]--;
                ans[2]--;
            }
        }
        else {
            
            for (int i = 3; i < k && i < 5; i += 2) {
                ans[0] -= 2; ans[1]--; ans[2]--;
                ans[i] = ans[i+1] = 2;
            }
            for (int i = 5; i < k; i += 4) {
                ans[i] = ans[i+1] = ans[i+2] = ans[i+3] = 1;
                ans[0] -= 2;
                ans[1]--;
                ans[2]--;
            }
        }
    }
    return ans;
}

vector<int> solve(int n, int k) {
    vector<int> ans(k);
    if (n % k == 0) {
        for (int i = 0; i < k; ++i) ans[i] = n/k;
    }
    if (k & 1) {
        if (n&1) {
            ans[0] = ans[1] = n/2; ans[2] = 1;
            for (int i = 3; i < k; i += 2) {
                ans[i] = ans[i+1] = 1;
                ans[0]--;
                ans[1]--;
            }
        }
        else {
            ans = solve2(n, k);
        }
    }
    else {
        if (n&1) {
            vector<int> tmp = solve2(n-1, k-1);
            for (int i = 0; i < k-1; ++i) ans[i] = tmp[i];
            ans[k-1] = 1;
        }
        else {
            ans[0]  = ans[1] = n/2;
            for (int i = 2; i < k; i += 2) {
                ans[i] = ans[i+1] = 1;
                ans[0]--;
                ans[1]--;
            }
        }
    }
    return ans;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> ans = solve(n, k);
        for (int i = 0; i < k; ++i) cout << ans[i] << " "; cout << endl;
    }

    return 0;
}
