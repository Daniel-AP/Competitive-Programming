#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

map<int, int> memo;

int dfs(int u, vector<vector<int>>& adj, map<pair<int, int>, int>& conn, vector<int>& parent) {

    if(memo.find(u) != memo.end()) return memo[u];

    int connu = (u == 1 ? -1 : conn[{ min(parent[u], u), max(parent[u], u) }]);
    memo[u] = 1;

    for(int v: adj[u]) {
        if(v == parent[u]) continue;
        int connv = conn[{ min(parent[v], v), max(parent[v], v) }];
        memo[u] = max(dfs(v, adj, conn, parent)+(connu>connv), memo[u]);
    }

    return memo[u];

}

void solve() {

    int n; cin >> n;

    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> parent(n+1);
    map<pair<int, int>, int> conn;

    memo.clear();

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        conn[{ min(u, v), max(u, v) }] = i;
    }

    queue<int> q;
    q.push(1);
    parent[1] = -1;

    while(!q.empty()) {

        int u = q.front(); q.pop();

        for(int v: adj[u]) {
            if(parent[v] != 0) continue;
            parent[v] = u;
            q.push(v);
        }

    }

    cout << dfs(1, adj, conn, parent) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}