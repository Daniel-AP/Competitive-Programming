#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<array<string, 2>> dp(n);
    dp[0][0] = a[0];
    dp[0][1] = a[0];

    for(int i = 1; i < n; i++) {
        dp[i][0] = min(a[i]+dp[i-1][0], a[i]+dp[i-1][1]);
        dp[i][1] = min(dp[i-1][0]+a[i], dp[i-1][1]+a[i]);
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}