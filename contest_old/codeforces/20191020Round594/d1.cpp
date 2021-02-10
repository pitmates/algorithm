//
// coded by zhuangliupeng
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


int calc(string s, int n) {
    int ans = 0, exam = 0, largestDiff = 0, loc = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') ++exam;
        else {
            --exam;
            if (exam < largestDiff) {
                largestDiff = exam;
                loc = i;
            }
        }
    }
    exam = 0;
    for (int i = loc+1; i <= n; ++i) {
        if (s[i] == '(') ++exam;
        else --exam;
        if (exam == 0) ++ans;
    }
    for (int i = 1; i <= loc; ++i) {
        if (s[i] == '(') ++exam;
        else --exam;
        if (exam == 0) ++ans;
    }
    return ans;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    s = "$" + s;

    int left = 1, right = 1, maxBra = 0, exam = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') ++exam;
        else --exam;
    }
    if (!exam) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                swap(s[i], s[j]);
                int bra = calc(s, n);
                if (bra > maxBra) {
                    maxBra = bra;
                    left = i;
                    right = j;
                }
                swap(s[i], s[j]);
            }
        }
    }
    cout << maxBra << endl << left << " " << right << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
