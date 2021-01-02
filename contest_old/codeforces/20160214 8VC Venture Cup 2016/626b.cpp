#include <iostream>
#include <cstring>

using namespace std;

int nu[3];
string c = "BGR";

int main()
{
    nu[0] = nu[1] = nu[2] = 0;
    int n, le = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'B') nu[0]++;
        else if(s[i] == 'G') nu[1]++;
        else nu[2]++;
    }
    for(int i = 0; i < 3; ++i) if(nu[i]) le++;
    if(le == 3) {
        cout << "BGR" << endl;
    } else if(le == 1){
        int k;
        for(int i = 0; i < 3; ++i) if(nu[i]){
            k = i;
            break;
        }
        cout << c[k] << endl;
    } else {
        int l = -1, r = -1;
        for(int i = 0; i < 3; ++i) {
            if(nu[i]) {
                if(l == -1) l = i;
                else r = i;
            }
        }
        if(n == 2) cout << c[3-l-r] << endl;
        else if(nu[l] == 1) {
            if(r == 1) r = 2;
            else l = 0, r = 1;
            cout << c[l] << c[r] << endl;
        } else if(nu[r] == 1) {
            if(l == 1) l = 0;
            else l = 1, r = 2;
            cout << c[l] << c[r] << endl;
        } else cout << c << endl;
    }
    return 0;
}
