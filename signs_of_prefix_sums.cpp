#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    if(s[0] == '0') return void(cout << -1 << '\n');

    for(int i = 0; i+1 < n; i++) {
        if(s[i] == '0' && s[i+1] == '0') return void(cout << -1 << '\n');
    }

    for(int i = 0; i+3 < n; i++) {
        if(s.substr(i, 4) == "+--+" || s.substr(i, 4) == "-++-") return void(cout << 3 << '\n');
    }

    for(int i = 0; i+1 < n; i++) {
        if(s.substr(i, 2) == "-+" || s.substr(i, 2) == "+-") return void(cout << 2 << '\n');
    }

    for(int i = 0; i < n; i++) {
        if(i%2 == 0 && s[i] == '0') return void(cout << 2 << '\n');
    }

    cout << 1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}