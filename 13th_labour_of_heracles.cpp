#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    vector<vector<int>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans += w[i];

    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < n; i++) {
        if(adj[i].size() <= 1) continue;
        pq.push({ w[i], adj[i].size()-1 });
    }

    cout << ans << ' ';

    for(int i = 1; i < n-1; i++) {

        if(!pq.empty()) {
            auto [val, deg] = pq.top(); pq.pop();
            ans += val;
            if(deg > 1) pq.push({ val, deg-1 });
        }

        cout << ans << ' ';
    }

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