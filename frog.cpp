#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n);
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        if(i-2 >= 0) {
            dp[i] = min(dp[i-1]+abs(h[i-1]-h[i]), dp[i-2]+abs(h[i-2]-h[i]));
        } else {
            dp[i] = dp[i-1]+abs(h[i-1]-h[i]);
        }
    }

    cout << dp[n-1] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}