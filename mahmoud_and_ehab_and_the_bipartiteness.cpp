#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, bool>> q;
    q.push({ 1, 0 });

    int o = 0, z = 0;

    while(!q.empty()) {
        auto [node, l] = q.front(); q.pop();
        visited[node] = 1;
        if(l) o++;
        else z++;
        for(int x: adj[node]) {
            if(visited[x]) continue;
            q.push({ x, !l });
        }
    }

    cout << o*z-(n-1) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}