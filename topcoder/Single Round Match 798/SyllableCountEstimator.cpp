#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

class SyllableCountEstimator {
    public:
    int estimate(string W) {
        int n = W.size();
        int ans = 0;
        map<char, int> mc;
        mc['a'] = mc['e'] = mc['i'] = mc['o'] = mc['u'] = 1;
        
        for (int i = 0; i < n; ++i) {
            ans += mc[W[i]];
        }
        // cout << ans << endl;
        for (int i = 1; i < n; ++i) {
            if (W[i] == 'u' && W[i-1] == 'a') --ans;
            if (W[i-1] == 'o' && W[i] == 'a') --ans;
            if (W[i-1] == 'o' && W[i] == 'o') --ans;
            if (i > 1 && W[i-2] == 'i' && W[i-1] == 'o' && W[i] == 'u') --ans;
        }
        if (W[n-1] == 'e') --ans;
        if (n > 2 && W[n-2] == 'l' && W[n-1] == 'e' && mc[W[n-3]] == 0) ++ans;

        if (ans == 0) ans = 1;
        return ans;
    }
};

// CUT begin
ifstream _greed_datas("SyllableCountEstimator.sample");

string next_line() {
    string s;
    getline(_greed_datas, s);
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

bool do_test(string W, int __expected) {
    time_t startClock = clock();
    SyllableCountEstimator *instance = new SyllableCountEstimator();
    int __result = instance->estimate(W);
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
        string W;
        from_stream(W);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(W, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1611421512;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SyllableCountEstimator (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
