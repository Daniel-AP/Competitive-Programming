#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, x; cin >> n >> x;

    vector<int> h(n+1), s(n+1), dp(x+1);

    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> s[i];

    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
        }
    }

    cout << dp[x] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}