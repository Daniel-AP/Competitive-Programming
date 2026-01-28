#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        int m, p; cin >> m >> p;
        a[i] = { m, p };
    }

    vector<int> dp(180+1);

    for(int i = 0; i < n; i++) {
        for(int j = 180; j >= a[i].first; j--) {
            dp[j] = max(dp[j], dp[j-a[i].first]+a[i].second);
        }
    }

    cout << dp[180] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}