#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
#define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> dp(n);
    dp[0] = 1;

    for(int i = 1; i < n; i++) {
        if(a[i] >= a[i-1] && b[i] >= b[i-1]) dp[i] += dp[i-1], dp[i] %= MOD;
        if(a[i] >= b[i-1] && b[i] >= a[i-1]) dp[i] += dp[i-1], dp[i] %= MOD;
    }

    cout << (2LL*dp[n-1])%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}