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
const int N = 55;

class StepsConstruct {
    public:
        bool vis[N][N];
        int dir[N][N];
        vector<int > path;
        int dx[5] = {0, -1, 1, 0, 0};
        int dy[5] = {0, 0, 0, -1, 1};
    string num2string(int x) {
        if(x == 1) return "U";
        if(x == 2) return "D";
        if(x == 3) return "L";
        if(x == 4) return "R";
    }

    string construct(vector<string> board, int K) {
        int n = sz(board), m = sz(board[0]);
        if(board[0][0] == '#' || board[n-1][m-1] == '#') return "";
        zero(dir); zero(vis); path.clear();
        queue<pii > q;
        while(!q.empty()) q.pop();
        q.push({0, 0}); vis[0][0] = 1;
        while(!q.empty()) {
            pii f = q.front(); q.pop();
            if(f.fi == n-1 && f.se == m-1) break;
            for(int i = 1; i < 5; ++i) {
                int x = f.fi + dx[i], y = f.se + dy[i];
                if(vis[x][y] || x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '#') continue;
                vis[x][y] = 1;
                q.push({x, y});
                dir[x][y] = i;
            }
        }
        int x = n-1, y = m-1;
        if(vis[x][y] == 0) return "";
        while(x || y) {
            int d = dir[x][y];
            path.pb(d);
            x -= dx[d], y -= dy[d];
        }
        int zs = sz(path);
        if(zs > K) return "";
        int k = K - zs;
        reverse(path.begin(), path.end());
        if(k&1) return "";
        int bo = path[zs-1];
        while(k) {
            if(bo == 1) path.pb(2);
            else if(bo == 2) path.pb(1);
            else if(bo == 3) path.pb(4);
            else path.pb(3);
            path.pb(bo);
            k -= 2;
        }
        string s = "";
        for(auto & i : path) s += num2string(i);
        return s;

    }
};

// CUT begin
ifstream data("StepsConstruct.sample");

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

bool do_test(vector<string> board, int k, string __expected) {
    time_t startClock = clock();
    StepsConstruct *instance = new StepsConstruct();
    string __result = instance->construct(board, k);
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
        int k;
        from_stream(k);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1487058127;
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
        cout << "StepsConstruct (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
