#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    set<int> s;

    for(int i = 0; i < 4; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    for(int i = 1; i <= 5; i++) {
        if(s.find(i) == s.end()) return void(cout << i << '\n');
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}