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
    
    vector<int> dp(n), best(n+1);
    dp[n-1] = 1, best[n-1] = 1;
    
    for(int i = n-2; i >= 0; i--) {
        if(i+a[i]+1 > n) dp[i] = n-i;
        else dp[i] = best[i+a[i]+1];
        best[i] = min(best[i+1]+1, dp[i]);
    }

    int ans = INF;
    for(int i = 0; i < n; i++) ans = min(ans, dp[i]+i);

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}