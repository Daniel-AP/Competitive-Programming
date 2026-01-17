#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> h0(n), h1(n);

    for(int i = 0; i < n; i++) cin >> h0[i];
    for(int i = 0; i < n; i++) cin >> h1[i];

    vector<array<int, 2>> dp(n);
    dp[0][0] = h0[0], dp[0][1] = h1[0];

    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][1]+h0[i];
        if(i-2 >= 0) dp[i][0] = max(dp[i][0], dp[i-2][1]+h0[i]);
        dp[i][1] = dp[i-1][0]+h1[i];
        if(i-2 >= 0) dp[i][1] = max(dp[i][1], dp[i-2][0]+h1[i]);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max({ ans, dp[i][0], dp[i][1] });
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}