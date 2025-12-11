#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

void solve() {

    int q, k; cin >> q >> k;

    vector<int> cnt(k+1), dp(k+1);
    dp[0] = 1;

    while(q--) {

        char op; cin >> op;
        int x; cin >> x;

        if(op == '+') {
            for(int i = k; i-x >= 0; i--) {
                dp[i] += dp[i-x];
                dp[i] %= MOD;
            }
        } else {
            for(int i = x; i <= k; i++) {
                dp[i] = (dp[i]-dp[i-x]+MOD)%MOD;
            }
        }

        cout << dp[k] << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}