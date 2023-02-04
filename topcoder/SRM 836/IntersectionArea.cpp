#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

class IntersectionArea {
    public:
    vector<int> addOne(vector<int> X1, vector<int> Y1, vector<int> X2, vector<int> Y2, long long A) {
        if (X1.size() == 0) {
            if (A == 0) return {};
            for (int i = 1; i <= 1e6; ++i) {
                if (A % i == 0 ) {
                    if (A / i <= 1e6) {
                        return {0, 0, i, (int)(A/i)};
                    }
                }
            }
            return {};
        }
        int xmin = *max_element(X1.begin(), X1.end());
        int xmax = *min_element(X2.begin(), X2.end());
        int ymin = *max_element(Y1.begin(), Y1.end());
        int ymax = *min_element(Y2.begin(), Y2.end());

        if (A == 0) {
            if (xmin != 0 || ymin != 0) {
                return {0, 0, 1, 1};
            }
            if (xmax != 1e6 || ymax != 1e6) {
                return {(int)1e6-1, (int)1e6-1, (int)1e6, (int)1e6};
            }
            return {};
        }

        if (xmin >= xmax || ymin >= ymax) return {};
        ll area = (xmax - xmin) * 1LL * (ymax - ymin);

        if (area < A) return {};

        for (int i = 1; i <= xmax - xmin; ++i) {
            if (A % i == 0) {
                ll w = A / i;
                if (w <= ymax - ymin) {
                    return {xmin, ymin, xmin+i, (int)(ymin+w)};
                }
            }
        }
        
        return {};
    }
};

// CUT begin
ifstream _greed_datas("IntersectionArea.sample");

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

bool do_test(vector<int> X1, vector<int> Y1, vector<int> X2, vector<int> Y2, long long A, vector<int> __expected) {
    time_t startClock = clock();
    IntersectionArea *instance = new IntersectionArea();
    vector<int> __result = instance->addOne(X1, Y1, X2, Y2, A);
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
        vector<int> X1;
        from_stream(X1);
        vector<int> Y1;
        from_stream(Y1);
        vector<int> X2;
        from_stream(X2);
        vector<int> Y2;
        from_stream(Y2);
        long long A;
        from_stream(A);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(X1, Y1, X2, Y2, A, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1661962817;
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
        cout << "IntersectionArea (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
