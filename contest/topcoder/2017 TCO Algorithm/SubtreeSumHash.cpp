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
const ll mo = (ll)1e9+7;
const int N = 55;

class SubtreeSumHash {
    public:
        ll ret;
        vector<int > E[N];
        ll dp[N];
        int X, w[N];

    ll multi_pow(ll x, int y) {
        ll res = 1LL;
        while(y) {
            if(y&1) (res *= x) %= mo;
            (x *= x) %= mo; y >>= 1;
        }
        return res;
    }

    void dfs(int u) {
        dp[u] = 1LL;
        for(auto & v : E[u]) {
            dfs(v);
            (dp[u] *= dp[v]) %= mo;
        }
        (dp[u] *= multi_pow(X, w[u])) %= mo;
        (ret += dp[u]) %= mo;
        (dp[u] += 1) %= mo;
    }

    int count(vector<int> weight, vector<int> p, int x) {
        ret = 0; X = x;
        int n = sz(p), m = sz(weight);
        rep(i, 0, m) w[i] = weight[i];
        rep(i, 0, N) E[i].clear();
        rep(i, 0, n) E[p[i]].pb(i+1);
        dfs(0);
        return (int)ret;
    }
};

// CUT begin
ifstream data("SubtreeSumHash.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(vector<int> weight, vector<int> p, int x, int __expected) {
    time_t startClock = clock();
    SubtreeSumHash *instance = new SubtreeSumHash();
    int __result = instance->count(weight, p, x);
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
        vector<int> weight;
        from_stream(weight);
        vector<int> p;
        from_stream(p);
        int x;
        from_stream(x);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(weight, p, x, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1491790521;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SubtreeSumHash (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
