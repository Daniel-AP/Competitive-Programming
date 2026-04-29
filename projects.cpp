#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<array<int, 3>> abp(n);

    for(int i = 0; i < n; i++) {
        auto& [a, b, p] = abp[i];
        cin >> a >> b >> p;
    }

    sort(all(abp));

    vector<int> dp(n);
    dp[n-1] = abp[n-1][2];

    for(int i = n-2; i >= 0; i--) {
        dp[i] = dp[i+1];
        int j = lower_bound(all(abp), array<int, 3>{abp[i][1]+1, -INF, -INF})-abp.begin();
        dp[i] = max(dp[i], abp[i][2]+(j == n ? 0 : dp[j]));
    }

    cout << dp[0] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}