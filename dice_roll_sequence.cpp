#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<array<int, 7>> dp(n);

    for(int i = 1; i <= 6; i++) dp[0][i] = (a[0]!=i);
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 6; j++) {
            dp[i][j] = INF;
            for(int k = 1; k <= 6; k++) {
                if(j == k || 7-k == j) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k]+(a[i]!=j));
            }
        }
    }

    int ans = INF;

    for(int i = 1; i <= 6; i++) {
        ans = min(ans, dp[n-1][i]);
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