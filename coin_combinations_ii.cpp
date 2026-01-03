#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;

    vector<int> c(n+1);
    for(int i = 1; i <= n; i++) cin >> c[i];

    sort(c.begin(), c.end());

    vector<int> dp(x+1);
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= x; j++) {
            if(j-c[i] >= 0) dp[j] += dp[j-c[i]];
            dp[j] %= MOD;
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