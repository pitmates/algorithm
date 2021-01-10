#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f

const int N = 55;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

class FlightPlan {
    public:
    bool isValid(int x, int y, int R, int C) {
        if (x < 0 || x >= R || y < 0 || y >= C) return false;
        return true;
    }
    long long fly(int R, int C, vector<int> H, int cup, int cdn, int clr) {
        vector<vector<int>> h(R, vector<int>(C));
        int top = H[0], bottom = H[R*C-1], minH = max(top, bottom);
        vector<int> satH;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                h[i][j] = H[i*C+j];
                if (h[i][j] >= minH) {
                    satH.push_back(h[i][j]);
                }
            }
        }
        
        ll minCost = INF;
        for (auto he : satH) {
            vector<vector<int>> d(R, vector<int>(C, inf));
            d[0][0] = 0;
            queue<pair<int, int>> Q;
            Q.push({0, 0});
            ll ans = 0;
            while (!Q.empty()) {
                auto z = Q.front();
                Q.pop();
                int x = z.first, y = z.second;
                if (x == R-1 && y == C-1) {
                    ans = 1LL * d[x][y] * clr + 1LL * (he - top) * cup + 1LL * (he - bottom) * cdn;
                    // printf("%d %d  %lld\n", d[x][y], he, ans);
                    minCost = min(ans, minCost);
                    break;
                }
                for (int i = 0; i < 4; ++i) {
                    int fx = dx[i] + x, fy = dy[i] + y;
                    if (!isValid(fx, fy, R, C)) continue;
                    if (d[fx][fy] != inf || h[fx][fy] > he) continue;
                    d[fx][fy] = d[x][y] + 1;
                    Q.push({fx, fy});
                }
            }
            while (!Q.empty()) Q.pop();
        }

        return minCost;
    }
};

// CUT begin
ifstream _greed_datas("FlightPlan.sample");

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

bool do_test(int R, int C, vector<int> H, int cup, int cdn, int clr, long long __expected) {
    time_t startClock = clock();
    FlightPlan *instance = new FlightPlan();
    long long __result = instance->fly(R, C, H, cup, cdn, clr);
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
        int R;
        from_stream(R);
        int C;
        from_stream(C);
        vector<int> H;
        from_stream(H);
        int cup;
        from_stream(cup);
        int cdn;
        from_stream(cdn);
        int clr;
        from_stream(clr);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(R, C, H, cup, cdn, clr, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1610213044;
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
        cout << "FlightPlan (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
