#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int m = n*(n+1)/2;

    if(m&1) return void(cout << 0 << '\n');

    vector<int> dp(m/2+1);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = m/2; j >= i; j--) {
            dp[j] += dp[j-i];
            dp[j] %= MOD;
        }
    }

    cout << dp[m/2]*500000004%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}