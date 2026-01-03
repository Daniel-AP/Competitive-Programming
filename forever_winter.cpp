#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>());

    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) continue;
        cnt[adj[i].size()]++;
    }

    auto it1 = cnt.begin();
    int j = it1->first;

    if(cnt.size() == 1) {
        if((j-1)+(j-1)*j == m) cout << j-1 << ' ' << j << '\n';
        else cout << j << ' ' << j-1 << '\n';
    } else {
        int x, y;
        auto it2 = next(it1);
        int k = it2->first;
        if(it1->second == 1) cout << j << ' ' << k-1 << '\n';
        else cout << k << ' ' << j-1 << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}