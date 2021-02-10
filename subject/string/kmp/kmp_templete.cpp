#include <bits/stdc++.h>


using namespace std;


vector<int > nxt;


void getNext(string p) {
    int n = p.size();
    nxt.resize(n);
    nxt[0] = -1;
    int i = 0, j = -1;
    while (i < n) {
        if (j == -1 || p[i] == p[j]) {
            ++i; ++j;
            if (p[i] == p[j]) {
                nxt[i] = nxt[j];
            }
            else {
                nxt[i] = j;
            }
        }
        else {
            j = nxt[j];
        }
    }
}

int kmp(string s, string p) {
    int n = s.size(), m = p.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || s[i] == p[j]) {
            ++i; ++j;
        }
        else {
            j = nxt[j];
        }
        if (j == m) return i - j;
    }
    return -1;
}

void printnxt() {
    for (auto x:nxt) cout << x << " ";
    cout << endl;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	string s = "abcdabcdabarg" , pattern = "abcdaba";
//	cin >> s >> pattern;
	getNext(pattern);
//	printnxt();
    int fir = kmp(s, pattern);
    string same = s.substr(fir, pattern.size());
	cout << fir << "  same: " << same << endl;

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
