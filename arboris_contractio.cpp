#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353


void solve() {

    int n; cin >> n;

    vector<vector<int>> adj(n+1, vector<int>());

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l = 0, ans = INF;

    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) l++;
    }

    for(int i = 1; i <= n; i++) {
        int cnt = adj[i].size() == 1;
        for(int x: adj[i]) cnt += adj[x].size() == 1;
        ans = min(ans, l-cnt);
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