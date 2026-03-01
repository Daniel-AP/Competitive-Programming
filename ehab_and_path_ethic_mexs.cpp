#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<vector<pair<int, int>>> adj(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    set<int> ind;

    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) ind.insert(adj[i][0].second);
    }

    set<int> lab;
    for(int i = 0; i < n-1; i++) lab.insert(i);

    vector<int> ans(n-1, -1);

    for(int i: ind) {
        ans[i] = *lab.begin();
        lab.erase(lab.begin());
    }

    for(int i = 0; i < n-1; i++) {
        if(ans[i] != -1) continue;
        ans[i] = *lab.begin();
        lab.erase(lab.begin());
    }

    for(int x: ans) cout << x << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}