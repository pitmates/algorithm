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

class SymmetryDetection {
    public:
    string detect(vector<string> board) {
        int n = sz(board), m = sz(board[0]);
        int f = 0, k;
        if(n == 1) f += 1;
        else if(n&1) {
            k = n/2;
            int ff = 1;
            for(int i = 0; i < k; ++i) {
                if(board[i] != board[n-i-1]) {
                    ff = 0;
                    break;
                }
            }
            if(ff) f += 1;
        }
        else {
            k = n/2-1;
            int ff = 1;
            for(int i = 0; i <= k; ++i) {
                if(board[i] != board[n-i-1]) {
                    ff = 0;
                    break;
                }
            }
            if(ff) f += 1;
        }
        if(m == 1) f += 2;
        else if(m&1) {
            k = m/2;
            int ff = 1;
            for(int i = 0; i < k; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(board[j][i] != board[j][m-i-1]) {
                        ff = 0;
                        break;
                    }
                }
                if(!ff) break;
            }
            if(ff) f += 2;
        }
        else {
            k = m/2-1;
            int ff = 1;
            for(int i = 0; i <= k; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(board[j][i] != board[j][m-i-1]) {
                        ff = 0;
                        break;
                    }
                }
                if(!ff) break;
            }
            if(ff) f += 2;
        }

        if(f == 0) return "Neither";
        else if(f == 1) return "Horizontally symmetric";
        else if(f == 2) return "Vertically symmetric";
        else return "Both";
    }
};

// CUT begin
ifstream data("SymmetryDetection.sample");

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

bool do_test(vector<string> board, string __expected) {
    time_t startClock = clock();
    SymmetryDetection *instance = new SymmetryDetection();
    string __result = instance->detect(board);
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
        string __answer;
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
        int T = time(NULL) - 1493254806;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SymmetryDetection (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
