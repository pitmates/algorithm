//
// Created by pitmates on 2019/11/25.
//

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

void quick_sort(vector<int > &arr) {
    vector<int > L, R;
    int seed = arr[0], n = arr.size();
    for (int i = 1; i < n; ++i) {
        if (arr[i] < seed) L.push_back(arr[i]);
        else R.push_back(arr[i]);
    }
    R.push_back(seed);
    int LS = L.size(), RS = R.size();
    if (LS > 1) quick_sort(L);
    if (RS > 1) quick_sort(R);
    for (int i = 0; i < LS; ++i) arr[i] = L[i];
    for (int i = 0; i < RS; ++i) arr[i+LS] = R[i];
}


void quick_sort(int L, int R, vector<int > &A) {
    int l = L, r = R-1;
    int seed = A[L];
    swap(A[L], A[R]);
    while (l < r) {
        while (A[l] < seed && l < r) ++l;
        while (A[r] >= seed && l < r) --r;
        swap(A[l], A[r]);
    }
    if (A[l] >= seed) --l;
    if (A[r] < seed) ++r;
//    cout << L << " " << R << " :  " << l << "  " << r << "  ";
//    for (int i = L; i <= R; ++i) cout << A[i] << " "; cout << endl;
    if (L < l) quick_sort(L, l, A);
    if (r < R) quick_sort(r, R, A);
}


void find_K(int L, int R, int K, int num, vector<int > &A) {
//    if (L >= R) return ;
    int l = L, r = R-1;
    int seed = A[L];
    swap(A[L], A[R]);
    while (l < r) {
        while (l < r && A[l] < seed) ++l;
        while (l < r && A[r] >= seed) --r;
        swap(A[l], A[r]);
    }
    if (A[l] >= seed) --l;
    if (A[r] < seed) ++r;

    int ls = l - L + 1, cnt = num + ls;

//    cout << L << " " << R << " : " << l << " " << r << "  + " << ls << " " << cnt << endl;

    if (cnt >= K) {
//        cout << "Left: " << L << " " << l << " " << num << "   ";
//        for (int i = L; i <= l; ++i) cout << A[i] << " "; cout << endl;
        if (L < l) find_K(L, l, K, num, A);
    }

    else {
//        cout << "Right: " << r << " " << R << " " << num+ls << "   ";
//        for (int i = r; i <= R; ++i) cout << A[i] << " "; cout << endl;

        if (r < R) find_K(r, R, K, num+ls, A);
    }
}


void test_qsort() {
    int n = 5, K = 2;
    K = n-K+1;
    vector<int > d(n, 0), ty(n, 0), tk;
    for (int i = 0; i < n; ++i) d[i] = i+1;
    int turn = 1;
    do {
//        d = {1, 2, 3, 4, 5};
        ty = d;
        tk = d;
        cout << turn ++  << " : ";
        for (auto x : ty) cout << x << " "; cout << " :: ";
        // cout << endl;
//        quick_sort(ty);
        quick_sort(0, n-1, tk);

//        cout << endl;
        find_K(0, n-1, K, 0, ty);
        cout << tk[K-1] << " +++ ";
        for (auto x : ty) cout << x << " "; cout  << " :+:  ";
        for (auto x : tk) cout << x << " "; cout << endl;
    }while (next_permutation(d.begin(), d.end()));
    return;
}


void test_tuple() {
    vector<tuple<int, int, int, int > > v = {{1, 3, 2, 1}, {3, 2, 4, 6}, {4, 5, 23, 1}};
    int cnt = 0;
    for(auto z : v){
        auto [x, y, _, __] = z;
        cout << x << " " << y << endl;
    }
    return;
}

void test_string() {
    string s = "123456789";
    int n = 3;
    cout << s.substr(9-n, n) << endl;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    cout << s << endl;
}


void test_lower() {
    vector<int > v = {3, 5, 6, 7, 8};
    auto x = lower_bound(v.begin(), v.end(), 9) - v.begin();
    cout << x << endl;
}



int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT
/*
hello world
 */
    ios_base::sync_with_stdio(false); cin.tie(0);


//    test_string();
//    test_tuple();
//    test_qsort();

    test_lower();

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
