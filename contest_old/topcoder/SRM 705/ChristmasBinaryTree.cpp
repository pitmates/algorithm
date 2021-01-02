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
const int N = 103;

class ChristmasBinaryTree {
    private:
        struct Matrix{
            int r, c;
            ll m[N][N];
            Matrix(int _=0, int __=0):r(_), c(__){
                zero(m);
            }
            void init() {
                rep(i, 0, r) m[i][i] = 1;
                return ;
            }
            void init(vector<int > a, vector<int > b) {
                int n = sz(a);
                rep(i, 0, n) m[i][a[i]]++, m[i][b[i]]++;
                return ;
            }
            Matrix operator * (const Matrix& a) const {
                Matrix t(r, a.c);
                rep(k, 0, c) rep(i, 0, r) if(m[i][k])rep(j, 0, a.c) {
                        (t.m[i][j] += m[i][k] * a.m[k][j]) %= mo;
                }
                return t;
            }
        };
    public:
    Matrix multi_pow(Matrix a, ll z) {
        Matrix b(a.r, a.c); b.init();
        while(z) {
            if(z & 1) b = b * a;
            a = a * a;
            z >>= 1;
        }
        return b;
    }

    ll sqr(ll x) {return (x*x) % mo; }

    int count(long long depth, vector<int> left, vector<int> right) {
        if(depth == 1) return 1;
        int n = sz(left);
        Matrix a(n, n); 
        a.init(left, right);
        Matrix b(n, n);
        b = multi_pow(a, depth-1);
        ll ans = 0;
        rep(i, 0, n) {
            ll tp = 0;
            rep(j, 0, n) (tp += sqr(b.m[i][j])) %= mo;
            ans = max(ans, tp);
        }
        return (int)ans;
    }
};

// CUT begin
ifstream data("ChristmasBinaryTree.sample");

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

bool do_test(long long depth, vector<int> left, vector<int> right, int __expected) {
    time_t startClock = clock();
    ChristmasBinaryTree *instance = new ChristmasBinaryTree();
    int __result = instance->count(depth, left, right);
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
        long long depth;
        from_stream(depth);
        vector<int> left;
        from_stream(left);
        vector<int> right;
        from_stream(right);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(depth, left, right, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1484207651;
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
        cout << "ChristmasBinaryTree (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
