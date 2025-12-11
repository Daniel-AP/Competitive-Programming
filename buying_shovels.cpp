#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    int ans = 0;

    for(int i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            if(i <= k) ans = max(ans, i);
            if(n/i <= k) ans = max(ans, n/i);
        }
    }

    cout << n/ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}