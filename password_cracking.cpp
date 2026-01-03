#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s;
    bool ok;

    set<string> asked;

    while(s.length() < n) {
        ok = false;
        if(asked.find(s+"0") == asked.end()) {
            cout <<  "? " << s+"0" << endl;
            asked.insert(s+"0");
            cin >> ok;
        }
        if(ok) {
            s += "0";
            continue;
        }
        if(asked.find(s+"1") == asked.end()) {
            cout << "? " << s+"1" << endl;
            asked.insert(s+"1");
            cin >> ok;
        }
        if(ok) {
            s += "1";
            continue;
        }
        break;
    }

    while(s.length() < n) {
        ok = false;
        if(asked.find("0"+s) == asked.end()) {
            cout <<  "? " << "0"+s << endl;
            asked.insert("0"+s);
            cin >> ok;
        }
        if(ok) s = "0"+s;
        else s = "1"+s;
    }

    cout << "! " << s << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}