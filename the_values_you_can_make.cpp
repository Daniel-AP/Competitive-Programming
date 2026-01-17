#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> c(n+1);
    for(int i = 1; i <= n; i++) cin >> c[i];

    vector<vector<bool>> dp(k+1, vector<bool>(k+1));
    dp[0][0] = 1;

    for(int j = 1; j <= n; j++) {
        for(int i = k; i >= c[j]; i--) {
            for(int l = 0; l <= k; l++) {
                if(dp[i-c[j]][l] == 0) continue;
                dp[i][l] = 1;
                if(l+c[j] <= k) dp[i][l+c[j]] = 1;
            }
        }
    }

    cout << count(all(dp[k]), 1) << '\n';
    for(int i = 0; i <= k; i++) if(dp[k][i]) cout << i << ' ';
    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}