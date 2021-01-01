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
#define ppl pair<pii, ll >

using namespace std;
const ll inf = (ll)1<<40;
const int N = 303;

class MinMaxMax {
    public:
    	ll fyd[N][N], E[N][N];
    	vector<pii > sv;
    long long findMin(vector<int> a, vector<int> b, vector<int> w, vector<int> v) {
    	sv.clear();
    	int n = sz(v), m = sz(w);
    	rep(i, 0, n) rep(j, 0, n) E[i][j] = inf;
    	rep(i, 0, n) rep(j, 0, n) fyd[i][j] = inf;
    	rep(i, 0, n) sv.pb({v[i], i});
    	sort(sv.begin(), sv.end());
    	rep(i, 0, m) E[a[i]][b[i]] = E[b[i]][a[i]] = w[i];
    	for(auto u : sv) {
    		int k = u.se;
    		rep(i, 0, n) rep(j, 0, n) {
    			E[i][j] = min(E[i][j], max(E[i][k], E[k][j]));
    			int y = max(v[i], max(v[k], v[j]));
    			fyd[i][j] = min(fyd[i][j], E[i][j]*y);
    		}
    	}
    	ll ans = 0;
    	rep(i, 0, n) rep(j, 1+i, n) ans += fyd[i][j];
    	return ans;
    }
};

// CUT begin
ifstream data("MinMaxMax.sample");

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

bool do_test(vector<int> a, vector<int> b, vector<int> w, vector<int> v, long long __expected) {
    time_t startClock = clock();
    MinMaxMax *instance = new MinMaxMax();
    long long __result = instance->findMin(a, b, w, v);
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
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        vector<int> w;
        from_stream(w);
        vector<int> v;
        from_stream(v);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, b, w, v, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1489131711;
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
        cout << "MinMaxMax (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
