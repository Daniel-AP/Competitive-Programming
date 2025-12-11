#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int cnt = count(s.begin(), s.end(), '0');

    if(cnt == 1) return void(cout << "BOB" << '\n');

    if(cnt%2) return void(cout << "ALICE" << '\n');
    else return void(cout << "BOB" << '\n');
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}