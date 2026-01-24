#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>());

    for(int i = 0; i < m; i++) {
        int k, u, v; cin >> k;
        if(!k) continue;
        cin >> u;
        for(int j = 0; j < k-1; j++) {
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<bool> vis(n+1);
    vector<int> ans(n+1);
    queue<int> q;

    for(int i = 1; i <= n; i++) {

        if(vis[i]) continue;

        vector<int> cur;

        q.push(i);
        vis[i] = 1;

        int cnt = 0;

        while(!q.empty()) {

            int u = q.front(); q.pop();

            cnt++;
            cur.push_back(u);

            for(int v: adj[u]) {
                if(vis[v]) continue;
                q.push(v);
                vis[v] = 1;
            }

        }

        for(int u: cur) ans[u] = cnt;

    }

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}