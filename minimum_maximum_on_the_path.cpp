#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, d; cin >> n >> m >> d;

    vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());

    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    int l = 0, r = 1e9, mid, ans = INF;

    while(l <= r) {

        mid = l+(r-l)/2;

        vector<bool> vis(n+1);

        queue<pair<int, int>> q;
        q.push({ 1, 0 });
        vis[1] = 1;

        bool can = false;

        while(!q.empty()) {

            auto [u, dd] = q.front(); q.pop();

            if(u == n) {
                can = true;
                break;
            }

            if(dd >= d) continue;

            for(auto [v, w]: adj[u]) {
                if(w > mid || vis[v]) continue;
                q.push({ v, dd+1 });
                vis[v] = 1;
            }

        }

        if(can) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }

    }

    if(ans == INF) return void(cout << -1 << '\n');
    
    vector<bool> vis(n+1);

    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    vis[1] = 1;

    vector<int> pre(n+1);

    while(!q.empty()) {
        
        auto [u, dd] = q.front(); q.pop();

        if(u == n) break;
        if(dd >= d) continue;

        for(auto [v, w]: adj[u]) {
            if(w > ans || vis[v]) continue;
            pre[v] = u;
            q.push({ v, dd+1 });
            vis[v] = 1;
        }

    }

    int u = n;

    vector<int> b;

    while(u) {
        b.push_back(u);
        u = pre[u];
    }

    reverse(all(b));

    cout << b.size()-1 << '\n';

    for(int x: b) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}