#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    string t = s;

    int n = s.length();

    if(n == 1) return void(cout << 1 << '\n');
    
    if(s.find("><") != string::npos) return void(cout << -1 << '\n');
    if(s.find("*<") != string::npos) return void(cout << -1 << '\n');
    if(s.find(">*") != string::npos) return void(cout << -1 << '\n');
    if(s.find("**") != string::npos) return void(cout << -1 << '\n');

    int i1 = s.rfind('<');
    int i2 = s.find('>');
    int cnt = count(s.begin(), s.end(), '*');

    if(i1 != string::npos && i2 != string::npos) {
        cout << max(i1+1+cnt, n-(i2-cnt)) << '\n';
    } else if(i1 != string::npos) {
        cout << i1+1+cnt << '\n';
    } else {
        cout << n-(i2-cnt) << '\n';
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}