#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();
    bool bad = false;

    int sz = 0, ns = -1, szs = 0;

    for(char ch: s) {
        if(ch == '-') {
            if(sz == ns) ns = -1;
            sz--;
            szs = min(szs, sz);
        }
        if(ch == '+') sz++;
        if(sz < 0) bad = true;
        if(ch == '0') {
            if(sz == szs || sz < 2) bad = true;
            else if(ns == -1) ns = sz;
        }
        if(ch == '1') {
            if(ns != -1) bad = true;
            szs = sz;
        }
    }

    cout << (bad ? "NO" : "YES") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}