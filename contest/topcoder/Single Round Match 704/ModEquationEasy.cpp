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
const ll mo = (ll)1e9+7;
const int N = 107;

class ModEquationEasy {
    public:

    struct Matrix {
        int r, c;
        ll m[N][N];
        Matrix(int _=0, int __=0):r(_), c(__){
            zero(m);
        }
        Matrix operator * (const Matrix& a) const {
            Matrix t(r, a.c);
            rep(i, 0, r) rep(j, 0, a.c) rep(k, 0, c) {
                (t.m[i][j] += m[i][k] * a.m[k][j]) %= mo;
            }
            return t;
        }
    };
    Matrix multi_pow(Matrix a, Matrix b, int n) {
        while(n) {
            if(n&1) b = b * a;
            a = a * a;
            n >>= 1;
        }
        return b;
    }

    int count(int n, int K, int v) {
        Matrix x(K, K), y(1, K);
        rep(i, 0, K) y.m[0][i] = 1;
        rep(i, 0, K) rep(j, 0, K) x.m[i][i*j%K]++;
        y = multi_pow(x, y, n-1);
        return y.m[0][v];
    }
};

// CUT begin
ifstream data("ModEquationEasy.sample");

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

bool do_test(int n, int K, int v, int __expected) {
    time_t startClock = clock();
    ModEquationEasy *instance = new ModEquationEasy();
    int __result = instance->count(n, K, v);
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
        int K;
        from_stream(K);
        int v;
        from_stream(v);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, K, v, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1483015191;
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
        cout << "ModEquationEasy (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
