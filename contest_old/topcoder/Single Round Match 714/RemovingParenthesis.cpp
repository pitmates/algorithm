#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define zero(x) memset((x), (0), sizeof (x))

using namespace std;
const int N = 22;

class RemovingParenthesis {
    public:
        int g[N];
    int dfs(int x, int r, int d, int dep, string s) {
        if(d == dep) return 1;
        int ans = 0, ju = 0;
        for(int i = x; i <= r; ++i) {
            if(s[i] == '(') ++ju;
            else if(s[i] != ')' && g[i] != 1) --ju;
            if(ju < 0) return 0;
        }
        for(int i = x+1; i <= r; ++i) {
            if(s[i] == ')' && g[i] != 1) {
                g[i] = 1;
                if(i == x+1) ans += dfs(x+2, r, d+1, dep, s);
                else ans += dfs(x+1, r, d+1, dep, s);
                g[i] = 0;
            }
        }
        return ans;
    }

    int countWays(string s) {
        int n = sz(s);
        int t = 0, l = 0, res = 1;
        zero(g);
        rep(i, 0, n) {
            if(s[i] == '(') ++t;
            else --t;
            if(t == 0) {
                res *= dfs(l, i, 0, (i-l+1)/2, s);
                l = i+1;
            }
        }

        return res;
    }
};

// CUT begin
ifstream data("RemovingParenthesis.sample");

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

bool do_test(string s, int __expected) {
    time_t startClock = clock();
    RemovingParenthesis *instance = new RemovingParenthesis();
    int __result = instance->countWays(s);
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
        string s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1494155047;
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
        cout << "RemovingParenthesis (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
