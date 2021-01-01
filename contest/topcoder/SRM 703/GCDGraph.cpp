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
const int N = 1000010;

class GCDGraph {
    public:
    //    vector<int > vx, vy;

    int f[N];
    int findset(int z) {
        if(z == f[z]) return z;
        return f[z] = findset(f[z]);
    }
    void unionset(int u, int v) {
        u = findset(u); v = findset(v);
        if(u != v) f[u] = v;
    }

    string possible(int n, int k, int x, int y) {
        if(x == y) return "Possible";
        if(__gcd(x, y) > k) return "Possible";
        if(x <= k || y <= k) return "Impossible";

        for(int i = 0; i <= n; ++i) f[i] = i;
        for(int i = k+1; i <= n; ++i) {
            for(int j = i; j <= n; j += i) unionset(j, i);
        }
        
        return findset(x) == findset(y) ? "Possible" : "Impossible";
    /**
        vx.clear(); vy.clear();
        rep(i, k+1, n+1) if(__gcd(x, i) > k) vx.pb(i);
        rep(i, k+1, n+1) if(__gcd(y, i) > k) vy.pb(i);
        rep(i, 0, sz(vx)) rep(j, 0, sz(vy)){
            if(__gcd(vx[i], vy[j]) > k) return "Possible";
        }
        return "Impossible";
    **/
    }
};

// CUT begin
ifstream data("GCDGraph.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, int k, int x, int y, string __expected) {
    time_t startClock = clock();
    GCDGraph *instance = new GCDGraph();
    string __result = instance->possible(n, k, x, y);
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
        int n;
        from_stream(n);
        int k;
        from_stream(k);
        int x;
        from_stream(x);
        int y;
        from_stream(y);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, k, x, y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1481681116;
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
        cout << "GCDGraph (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
