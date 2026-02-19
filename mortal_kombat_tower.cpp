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

    if(n == 1) return void(cout << a[0] << '\n');

    vector<array<int, 4>> dp(n);

    dp[1][0] = a[0]+a[1], dp[1][1] = INF, dp[1][2] = INF, dp[1][3] = a[0];

    for(int i = 2; i < n; i++) {
        dp[i][0] = dp[i-1][2]+a[i];
        dp[i][1] = dp[i-1][3];
        dp[i][2] = min(dp[i-1][1], dp[i-1][3])+a[i];
        dp[i][3] = min(dp[i-1][0], dp[i-1][2]);
    }

    cout << min({ dp[n-1][0], dp[n-1][1], dp[n-1][2], dp[n-1][3] }) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}