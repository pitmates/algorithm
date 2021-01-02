#include <bits/stdc++.h>
using namespace std;

class IslandInALake {
    public:
    vector<int> dx = {-1, 0, 0, 1, -1, -1, 1, 1};
    vector<int> dy = {0, -1, 1, 0, -1, 1, -1, 1};
    int dfs(vector<string> &C, int x, int y, int n, int m, bool isEig) {
        
        if (x < 0 || x >= n || y < 0 || y >= m) return 0;
        int B = isEig ? 8 : 4;
        int ans = 1;
    
        if (C[x][y] != '.') return 0;
        if (isEig) C[x][y] = '^';
        else C[x][y] = '$';
        for (int i = 0; i < B; ++i) {
            ans += dfs(C, x+dx[i], y+dy[i], n, m, isEig);
        }
    
        return ans;
    }

    void fill_bd(vector<string> &C, int x, int y, int n, int m) {
        for (int i = 0; i < 8; ++i) {
            int fx = dx[i] + x, fy = dy[i] + y;
            if (fx < 0 || fx >= n || fy < 0 || fy >= m) continue;
            if (C[fx][fy] == '.') C[fx][fy] = 'S';
        }
    }
    int build(vector<string> C) {
        int n = C.size();
        int m = C[0].size();
        dfs(C, 0, 0, n, m, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (C[i][j] != '#') continue;
                fill_bd(C, i, j, n, m);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (C[i][j] != '.') continue;
                int mx = dfs(C, i, j, n, m, true);
                ans = max(mx, ans);
            }
        }
        return ans;
    }
};

// CUT begin
ifstream _greed_datas("IslandInALake.sample");

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

bool do_test(vector<string> country, int __expected) {
    time_t startClock = clock();
    IslandInALake *instance = new IslandInALake();
    int __result = instance->build(country);
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
        vector<string> country;
        from_stream(country);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(country, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1607145889;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "IslandInALake (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
