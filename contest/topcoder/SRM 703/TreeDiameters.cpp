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
const int N = 2020;

class TreeDiameters {
    public:
    vector<int > E[N];
    int dis[N];
    int sum[N], sum2[N];

    void dfs(int x, int parent, int depth) {
        ++dis[depth];
        for(int y : E[x]) if(y != parent) 
            dfs(y, x, depth+1);
    }

    int getMax(vector<int> p) {
        if(sz(p) == 1) return 1;
        for(int i = 0; i < N; ++i) E[i].clear();
        int n = sz(p);
        for(int i = 0; i < n; ++i) {
            E[p[i]].pb(n+i+2); E[n+i+2].pb(p[i]);
            E[i+1].pb(n+i+2); E[n+i+2].pb(i+1);
        }
        int ans = 0;
        rep(i, 0, n+n+2) {
            zero(sum); zero(sum2);
            for(int x : E[i]){
                zero(dis);
                dfs(x, i, 1);
            //rep(j, 1, n+1) printf("%d ", dis[j]); puts("");
                rep(j, 1, n+1) {
                    sum[j] += dis[j];
                    sum2[j] += dis[j] * dis[j];
                }
            }
            rep(j, 1, n+1) 
                ans = max(ans, (sum[j]*sum[j] - sum2[j])/2);
        }
        return ans;
    }
};

// CUT begin
ifstream data("TreeDiameters.sample");

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

bool do_test(vector<int> p, int __expected) {
    time_t startClock = clock();
    TreeDiameters *instance = new TreeDiameters();
    int __result = instance->getMax(p);
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
        vector<int> p;
        from_stream(p);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1481705530;
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
        cout << "TreeDiameters (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
