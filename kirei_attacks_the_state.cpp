#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> parent(n+1, -1);
    vector<vector<int>> adj(n+1);

    parent[0] = parent[1] = 0;

    for(int i = 1; i < n; i++) {
        int v, u; cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> dp(n+1);
    queue<int> q;

    q.push(1);

    while(!q.empty()) {

        int u = q.front(); q.pop();

        if(parent[parent[u]] == 0) dp[u] = a[u];
        else {
            dp[u] = max(a[u], a[u]+dp[parent[parent[u]]]-a[parent[u]]);
        }
        
        for(int v: adj[u]) {
            if(parent[v] != -1) continue;
            parent[v] = u;
            q.push(v);
        }

    }

    for(int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}