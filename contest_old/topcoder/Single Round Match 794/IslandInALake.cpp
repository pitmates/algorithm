#include <bits/stdc++.h>
using namespace std;

class IslandInALake {
    public:
    bool my_search(int x, int y, int n, int m, vector<vector<int>> &G) {
        int dx[] = {0, 1, -1, 0};
        int dy[] = {-1, 0, 0, 1};
        queue<pair<int, int >> Q;
        bool is_sea = false;
        Q.push({x, y});
        G[x][y] = 2;
        while (!Q.empty()) {
            auto F = Q.front();
            Q.pop();
            int u = F.first, v = F.second;
            for (int i = 0; i < 4; ++i) {
                int fx = u + dx[i], fy = v + dy[i];
                if (fx < 0 || fx >= n || fy < 0 || fy >= m) continue;
                if (G[fx][fy] != 0) continue;
                Q.push({fx, fy});
                G[fx][fy] = 2;
                if (fx == 0 || fx == n-1 || fy == 0 || fy == m-1) is_sea = true;
            }
        }
        return is_sea;
    }

    int find_land(int x, int y, int n, int m, vector<vector<int>> &G) {
        int dx[] = {0, 1, -1, 0};
        int dy[] = {-1, 0, 0, 1};
        queue<pair<int, int >> Q;
        vector<pair<int, int >> V;
        V.clear(); 
        Q.push({x, y});
        G[x][y] = 3;
        while (!Q.empty()) {
            auto F = Q.front();
            Q.pop();
            int u = F.first, v = F.second;
            int f = 0;
            for (int i = 0; i < 4; ++i) {
            for (int i = -1; i < 2; ++i) for (int j = -1; j < 2; ++j) {
                int fx = u + i, fy = v + j;
                if (fx < 0 || fx >= n || fy < 0 || fy >= m) continue;
                if (G[fx][fy] == -1) {
                    f = 1;
                    continue;
                }
                if (G[fx][fy] != 2) continue;
                Q.push({fx, fy});
                G[fx][fy] = 3;
            }
            if (f == 1) G[u][v] = 4;
            else V.push_back({u, v});
        }
        int mx = 0;
        
        printf("---- %d\n", V.size());
        for (auto p : V) {
            if (G[p.first][p.second] == 5) continue;
            while (!Q.empty()) Q.pop();
            Q.push(p);
            int cnt = 1;
            G[p.first][p.second] = 5;
            while (!Q.empty()) {
                auto F = Q.front();
                Q.pop();
                int u = F.first, v = F.second;
               
                for (int i = 0; i < 4; ++i) {
                    int fx = u + dx[i], fy = v + dy[i];
                    if (fx < 0 || fx >= n || fy < 0 || fy >= m) continue;
                    if (G[fx][fy] != 3) continue;    
                    if (fx == 0 || fx == n-1 || fy == 0 || fy == m-1) continue;                
                    Q.push({fx, fy});
                    G[fx][fy] = 5;
                    ++cnt;
                }
            }
            printf("  %d  %d\n", cnt, mx);
            mx = max(cnt, mx);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) printf(" %d", G[i][j]);
            printf("\n");
        }
        
        return mx;
    }

    int build(vector<string> country) {
        int n = country.size();
        int m = country[0].size();
        vector<vector<int>> G(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (country[i][j] == '.') G[i][j] = 0;
                else G[i][j] = -1;
            }
        }
        int mx = 0;
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (G[i][j] != 0) continue;
                if (my_search(i, j, n, m, G)) continue;
                int local_mx = find_land(i, j, n, m, G);
                mx = max(mx, local_mx);
            }
        }
        return mx;
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
        int T = time(NULL) - 1607099050;
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
