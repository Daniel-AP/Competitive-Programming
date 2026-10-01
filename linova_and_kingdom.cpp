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

    vector<int> ssz(n+1), dist(n+1, -1);
    priority_queue<pair<int, int>> pq;

    auto dfs1 = [&](auto& self, int u, int p) -> int {
        int sz = 1;
        for(int v: adj[u]) {
            if(v != p) sz += self(self, v, u);
        }
        ssz[u] = sz;
        return sz;
    };
    
    auto bfs = [&](int u) -> void {
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int w: adj[v]) {
                if(dist[w] != -1) continue;
                q.push(w);
                dist[w] = dist[v]+1;
            }
        }
    };

    dfs1(dfs1, 1, -1);
    bfs(1);

    for(int i = 1; i <= n; i++) {
        pq.push({ ssz[i]-dist[i], i });
    }

    int tour = n-k;
    vector<bool> tourism(n+1);

    while(tour--) {
        auto [_, u] = pq.top(); pq.pop();
        tourism[u] = 1;
    }

    int ans = 0;

    auto dfs2 = [&](auto& self, int u, int p) -> int {
        int cnt = !tourism[u];
        for(int v: adj[u]) {
            if(v != p) cnt += self(self, v, u);
        }
        if(tourism[u]) ans += cnt;
        return cnt;
    };

    dfs2(dfs2, 1, -1);

    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}