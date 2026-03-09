#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n%2) return void(cout << -1 << '\n');

    int ans = 0;

    vector<int> parent(n+1, -1), order;
    queue<int> q;

    q.push(1);
    parent[1] = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for(int v: adj[u]) {
            if(parent[v] != -1) continue;
            parent[v] = u;
            q.push(v);
        }
    }

    vector<int> dp(n+1, 1);

    for(int i = n-1; i > 0; i--) {
        int u = order[i];
        for(int v: adj[u]) {
            if(parent[u] == v) continue;
            dp[u] += dp[v];
        }
        ans += (1-dp[u]%2);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}