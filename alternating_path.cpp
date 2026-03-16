#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n+1, -1);
    vector<bool> vis(n+1);
    queue<int> q;

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(dist[i] != -1) continue;
        bool bad = false;
        q.push(i);
        dist[i] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v: adj[u]) {
                if(dist[v] != -1) {
                    bad |= (dist[v]%2 != (dist[u]+1)%2) || (dist[v] == dist[u]);
                } else {
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        while(!q.empty()) q.pop();
        if(bad) continue;
        q.push(i);
        vis[i] = 1;
        int even = 1, odd = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v: adj[u]) {
                if(vis[v]) continue;
                vis[v] = 1;
                even += 1-dist[v]%2;
                odd += dist[v]%2;
                q.push(v);
            }
        }
        ans += max(even, odd);
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