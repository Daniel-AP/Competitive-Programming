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

    set<int> s{1};
    vector<bool> vis(n+1);

    while(!s.empty()) {
        int u = *s.begin(); s.erase(s.begin());
        vis[u] = 1;
        cout << u << ' ';
        for(int v: adj[u]) {
            if(vis[v]) continue;
            s.insert(v);
        }
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}