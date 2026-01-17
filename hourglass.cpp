#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int s, k, m; cin >> s >> k >> m;
    int q = min(s, k);

    if(s <= k) {
        cout << max(s-m+(m/k)*k, 0LL);
    } else {
        cout << max(q-m+(m/k)*k, 0LL);
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}