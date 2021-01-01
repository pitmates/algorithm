#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const ll mo = (ll)1e9+7;
const int N = 103;

class RainbowGraph {
    public:
        ll dp[1<<10][N];
        bool con[N][N];
        int path[N][N];
        vector<int > cor[10];

    int countWays(vector<int> color, vector<int> a, vector<int> b) {
        zero(dp);
        zero(con);
        zero(path);
        rep(i, 0, 10) cor[i].clear();

        rep(i, 0, sz(color)) cor[color[i]].pb(i);
        rep(i, 0, sz(a)) con[a[i]][b[i]] = con[b[i]][a[i]] = 1;
        int cr = 0;
        rep(i, 0, 10) if(cor[i].empty()) cr |= (1<<i);

        rep(c, 0, 10) if(!cor[c].empty()) {
            do{
                int i, z = sz(cor[c]);
                for(i = 0; i < z-1; ++i) if(!con[cor[c][i]][cor[c][i+1]]) break;
                if(i == z-1) {
                    path[cor[c][0]][cor[c].back()]++;
                    dp[cr|(1<<c)][cor[c].back()]++;
                }
            } while(next_permutation(cor[c].begin(), cor[c].end()));
        }

        rep(u, 1, (1<<10)) rep(c, 0, 10) if((u & (1<<c)) == 0) {
            rep(i, 0, N) if(dp[u][i]) for(int x:cor[c]) if(con[i][x]) {
                for(int y:cor[c]) if(path[x][y]) {
                    (dp[u|(1<<c)][y] += dp[u][i] * path[x][y]) %= mo;
                }
            }
        }
        ll ans = 0;
        rep(i, 0, N) (ans += dp[(1<<10)-1][i]) %= mo;
        return (int)ans;
    }
};

// CUT begin
ifstream data("RainbowGraph.sample");

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

bool do_test(vector<int> color, vector<int> a, vector<int> b, int __expected) {
    time_t startClock = clock();
    RainbowGraph *instance = new RainbowGraph();
    int __result = instance->countWays(color, a, b);
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
        vector<int> color;
        from_stream(color);
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(color, a, b, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503631460;
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
        cout << "RainbowGraph (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
