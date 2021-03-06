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
const int N = 1000100;
const ll mo = (1ll)1e9+7;

class PowerEquationEasy {
    public:
        int g[N], vec[N], pr[N];
        ll ans[N];

    int count(int n) {
        
        zero(pr);
        
        for(int i = 2; i <= n; ++i) {
            for(int j = i*i; j <= n; j += i) {
                pr[j] = 1;
            }
        }
        for(int i = 0; i <= n; ++i) g[i] = i, vec[i] = 0;
        for(int i = 2; i <= n; ++i) if(g[i] == i){
            int t = 0;
            for(int j = i*i; j <= n; j *= i) {
                vec[j] = i; ++t;
            }
            g[i] = t;
        }
        ll res = 1LL * n * n;
        for(int i = 2; i <= n; ++i) {
            if(vec[i] != i) {
                (res += ans[vec[i]]) %= mo;
                continue;
            }
            int t = i, s = 1;
            for(int j = 2; j * j <= t; ++j) {
                if(pr[j]) continue;
                if(t % j) continue;
                int k = 0;
                while(t % j == 0) t /= j, ++k;
                s = s * (k+1);
            }
            if(t > 1) s *= 2;
            ans[i] = 
            (res += ans[i]) %= mo;
        }
        return 0;
    }
};

// CUT begin
ifstream data("PowerEquationEasy.sample");

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

bool do_test(int n, int __expected) {
    time_t startClock = clock();
    PowerEquationEasy *instance = new PowerEquationEasy();
    int __result = instance->count(n);
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
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1493255965;
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
        cout << "PowerEquationEasy (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
