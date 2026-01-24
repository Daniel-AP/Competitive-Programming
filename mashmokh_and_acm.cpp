#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<vector<int>> dp(n+1, vector<int>(k+1));

    for(int i = 1; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= n; i++) dp[i][1] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < k; j++) {
            for(int d = i; d <= n; d += i) {
                dp[d][j+1] += dp[i][j];
                dp[d][j+1] %= MOD;
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) ans += dp[i][k], ans %= MOD;

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}