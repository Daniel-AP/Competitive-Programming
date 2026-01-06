#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;

    vector<int> h(n+1), s(n+1);

    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> s[i];

    vector<int> dp(x+1);

    for(int j = 1; j <= n; j++) {
        for(int i = x; i >= h[j]; i--) {
            dp[i] = max(dp[i-h[j]]+s[j], dp[i]);
        }
    }

    cout << dp[x] << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}