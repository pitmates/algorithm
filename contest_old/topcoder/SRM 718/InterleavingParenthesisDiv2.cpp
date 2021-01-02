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
const ll mo = (ll)1e9+7;
const int N = 53;

class InterleavingParenthesisDiv2 {
    public:
        ll dp[N<<1][N][N];
    int countWays(string s1, string s2) {
        int n = sz(s1), m = sz(s2);
        if((n+m) & 1) return 0;
        int k = 0;
        rep(i, 0, n) if(s1[i] == '(') ++k;
        rep(i, 0, m) if(s2[i] == '(') ++k;
        if(k + k != n+m) return 0;
        zero(dp);
        if(s1[0] == '(') dp[1][0][1] = 1;
        if(s2[0] == '(') dp[1][1][1] = 1;
        rep(i, 2, n+m+1) {
            if(i <= n) rep(k, 0, 1+i) {
                    if(s1[i-1] == '(') {
                        if(k) dp[i][0][k] = dp[i-1][0][k-1];
                    }
                    else {
                        if(k<i) dp[i][0][k] = dp[i-1][0][k+1];
                    }
                }
            rep(j, 1, min(1+i, 1+m)) {
                int p1 = i-j-1, p2 = j;
                rep(k, 0, min(1+i, N)) {
                    if(p1 >= 0){
                        if(s1[p1] == '(') {
                            if(k) dp[i][j][k] = dp[i-1][j][k-1];
                        }
                        else {
                            if(k<i) dp[i][j][k] = dp[i-1][j][k+1];
                        }
                    }
                    if(s2[p2-1] == '(') {
                        if(k) (dp[i][j][k] += dp[i-1][j-1][k-1])%=mo;
                    }
                    else {
                        if(k<i) (dp[i][j][k] += dp[i-1][j-1][k+1])%=mo;
                    }
                }
            }
        }
// rep(i, 1, n+m+1) {
//     printf("i:   ++++  %d\n", i);
//     rep(j, 0, 1+i) {
//         printf("  j:%d :  ", j);
//         rep(k, 0, 1+i) printf("%I64d ", dp[i][j][k]); puts("");
//     }
// }
        cout << dp[n+m][m][0] << endl;
        return dp[n+m][m][0];
    }
};

// CUT begin
ifstream data("InterleavingParenthesisDiv2.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string s1, string s2, int __expected) {
    time_t startClock = clock();
    InterleavingParenthesisDiv2 *instance = new InterleavingParenthesisDiv2();
    int __result = instance->countWays(s1, s2);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string s1;
        from_stream(s1);
        string s2;
        from_stream(s2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s1, s2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500534551;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "InterleavingParenthesisDiv2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
