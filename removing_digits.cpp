#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> dp(n+1, INF);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        string s = to_string(i);
        for(char c: s) if(i-(c-'0') >= 0) dp[i] = min(dp[i], 1+dp[i-(c-'0')]);
    }

    cout << dp[n] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}