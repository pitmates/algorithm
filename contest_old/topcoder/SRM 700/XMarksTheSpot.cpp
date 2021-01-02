#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second

using namespace std;

class XMarksTheSpot {
    public:
    int countArea(vector<string> board) {
        int ans, L, R, T, B;
        ans = 0; R = B = -1; L = T = 51;
        vector<pii > p; p.clear();
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
                if(board[i][j] == 'O'){
                    L = min(L, j); T = min(T, i);
                    R = max(R, j); B = max(B, i);
                }
                if(board[i][j] == '?') p.push_back({i, j});
        }
        int x = p.size();
        for(int i = 0; i < (1<<x); ++i) {
            int l = L, r = R, t = T, b = B;
            for(int j = 0; j < 22; ++j) {
                if((1 << j) & i) {
                    l = min(l, p[j].se), r = max(r, p[j].se);
                    t = min(t, p[j].fi), b = max(b, p[j].fi);
                }
            }
            ans += (r-l+1) * (b-t+1);
        }
        return ans;
    }
};

// CUT begin
ifstream data("XMarksTheSpot.sample");

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

bool do_test(vector<string> board, int __expected) {
    time_t startClock = clock();
    XMarksTheSpot *instance = new XMarksTheSpot();
    int __result = instance->countArea(board);
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
        vector<string> board;
        from_stream(board);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1476362309;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "XMarksTheSpot (450 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
