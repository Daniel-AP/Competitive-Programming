#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    int ans = 0;

    set<int> can{n};

    while(true) {
        if(can.find(k) != can.end()) return void(cout << ans << '\n');
        set<int> can2;
        for(int x: can) {
            can2.insert(x/2);
            can2.insert((x+1)/2);
        }
        if(can == can2) break;
        can = can2;
        ans++;
    }

    cout << -1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}