#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = (g[0][0] != '*');

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == '*') continue;
            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n-1][n-1] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}