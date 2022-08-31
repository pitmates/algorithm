#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

class PartialSumPyramid {
    public:
    vector<int> reconstruct(int N, int M, vector<int> index, vector<int> value) {
        vector<vector<int>> G(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            G[i][index[i]] = value[i];
        }

        for (int rw = 1; rw < N; ++rw) {
            int l = index[rw] - 1, r = index[rw] + 1;
            while (l >= 0) {
                if (G[rw-1][l] < G[rw][l+1]) {
                    G[rw][l] = G[rw-1][l] + M - G[rw][l+1];
                }
                else {
                    G[rw][l] = G[rw-1][l] - G[rw][l+1];
                }
                l--;
            }

            while (r <= rw) {
                if (G[rw-1][r-1] < G[rw][r-1]) {
                    G[rw][r] = G[rw-1][r-1] + M - G[rw][r-1];
                }
                else {
                    G[rw][r] = G[rw-1][r-1] - G[rw][r-1];
                }
                r++;
            }
        }

        vector<int> res = G[N-1];
        return res;
    }
};

// CUT begin
ifstream _greed_datas("PartialSumPyramid.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int N, int M, vector<int> index, vector<int> value, vector<int> __expected) {
    time_t startClock = clock();
    PartialSumPyramid *instance = new PartialSumPyramid();
    vector<int> __result = instance->reconstruct(N, M, index, value);
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
        int N;
        from_stream(N);
        int M;
        from_stream(M);
        vector<int> index;
        from_stream(index);
        vector<int> value;
        from_stream(value);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, M, index, value, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1661955165;
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
        cout << "PartialSumPyramid (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
