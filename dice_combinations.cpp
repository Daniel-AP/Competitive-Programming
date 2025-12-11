#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> dp(n+1);
    dp[0] = 1;
    
    for(int i = 0; i <= n; i++) {
        if(dp[i] == 0) continue;
        for(int j = 1; j <= 6 && i+j <= n; j++) dp[i+j] += dp[i], dp[i+j] %= MOD;
    }

    cout << dp[n] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}