#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> szu(n), par(n);

    auto dfs = [&](auto&& self, int u, int p) -> int {
        szu[u] = 1;
        par[u] = p;
        for(int v: adj[u]) {
            if(v == p) continue;
            szu[u] += self(self, v, u);
        }
        return szu[u];
    };

    dfs(dfs, 0, -1);

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int u = i, sqrtu = sqrtl(a[u]);
        if(sqrtu*sqrtu != a[u]) continue;
        int acc1 = 0, acc2 = 0;
        for(int v: adj[u]) {
            if(v == par[u]) {
                ans += acc2*(n-szu[u]);
                acc2 += acc1*(n-szu[u]);
                ans += acc1*(n-szu[u]);
                acc1 += (n-szu[u]);
            } else {
                ans += acc2*szu[v];
                acc2 += acc1*szu[v];
                ans += acc1*szu[v];
                acc1 += szu[v];
            }
        }
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