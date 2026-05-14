#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int dfs(int u, int p, int x, vector<int>& dp, vector<vector<int>>& adj) {

    if(dp[u] != -1) return dp[u];
    dp[u] = 1;

    for(int v: adj[u]) {
        if(v == p) continue;
        dp[u] += dfs(v, u, x, dp, adj);
    }

    if(dp[u] >= x) dp[u] = 0;

    return dp[u];

}

void solve() {

    int n, k; cin >> n >> k;
    int l = 1, r = n, mid, ans = 0;

    vector<vector<int>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(l <= r) {
        mid = l+(r-l)/2;
        vector<int> dp(n, -1);
        dfs(0, -1, mid, dp, adj);
        bool can = (count(all(dp), 0LL) != 0);
        can &= (count(all(dp), 0LL) >= k+1);
        if(can) {
            l = mid+1;
            ans = mid;
        } else {
            r = mid-1;
        }
    }

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