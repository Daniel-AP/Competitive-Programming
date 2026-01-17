#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, k; cin >> n >> m >> k;
    int mx = max(k-1, n-k), mn = min(k-1, n-k);

    int ans = 0;

    for(int i = 0; i <= mx; i++) {

        int j = i+1, cur = 1, q = m;

        q -= i;
        cur += min({ q, j, mx });
        j = min({ q, j, mx });
        int t = j;
        q -= min(q, t);
        cur += min({ q, j, mn });
        q -= min({ q, j, mn });
        
        ans = max(ans, cur);

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}