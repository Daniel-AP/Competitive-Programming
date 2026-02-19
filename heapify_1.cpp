#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> adj(n+1);

    for(int i = 1; i <= n; i++) {
        for(int j = 2*i; j <= n; j *= 2) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    vector<int> cc(n+1);
    vector<bool> vis(n+1);

    int id = 1;

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(vis[u]) continue;
            cc[u] = id;
            vis[u] = 1;
            for(int v: adj[u]) {
                if(vis[v]) continue;
                q.push(v);
            }
        }
        id++;
    }

    vector<int> ind(n);
    iota(all(ind), 1);
    sort(all(ind), [&](int i, int j) {
        return a[i] < a[j];
    });

    bool can = true;

    for(int i = 1; i <= n; i++) {
        int j = ind[i-1];
        if(cc[i] != cc[j]) can = false;
    }

    cout << (can ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}