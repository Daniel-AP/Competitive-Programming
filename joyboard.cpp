#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, k; cin >> n >> m >> k;
    
    if(k == 1) {
        cout << 1 << '\n';
    } else if(k == 2) {
        cout << min(n, m)+max(m/n-1, 0LL) << '\n';
    } else if(k == 3) {
        cout << max(m-n+1, 0LL)-m/n << '\n';
    } else {
        cout << 0 << '\n';
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