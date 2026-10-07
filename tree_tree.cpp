#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<vector<int>> adj(n+1);
    
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sub(n+1), sz(n+1);

    auto dfs1 = [&](auto& self, int u, int par) -> pair<int, int> {
        int cnt = 1, s = 0;
        for(int v: adj[u]) {
            if(v == par) continue;
            auto [c, ss] = self(self, v, u);
            cnt += c;
            s += ss;
        }
        s += (cnt>=k);
        sub[u] = s;
        sz[u] = cnt;
        return {cnt, s};
    };

    dfs1(dfs1, 1, -1);

    vector<int> dp(n+1);
    dp[1] = sub[1];

    auto dfs2 = [&](auto& self, int u, int par) -> void {
        for(int v: adj[u]) {
            if(v == par) continue;
            dp[v] = dp[u]-(n-sz[v]<k)+(sz[v]<k);
        }
        for(int v: adj[u]) {
            if(v == par) continue;
            self(self, v, u);
        }
    };

    dfs2(dfs2, 1, -1);

    int ans = 0;
    for(int i = 1; i <= n; i++) ans += dp[i];

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