#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    vector<double> c(n), p(n);

    for(int i = 0; i < n; i++) {
        cin >> c[i] >> p[i];
    }

    vector<double> dp(n);
    dp[n-1] = c[n-1];

    double mx = dp[n-1];

    for(int i = n-2; i >= 0; i--) {
        dp[i] = max(c[i]+(1-p[i]/100)*mx, dp[i+1]);
        mx = max(mx, dp[i]);
    }

    cout << fixed << setprecision(9) << dp[0] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}