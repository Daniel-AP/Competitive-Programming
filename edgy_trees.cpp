#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b%2) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }

    return ans;

}

void solve() {

    int n, k; cin >> n >> k;

    vector<vector<int>> adj(n+1);

    for(int i = 1; i < n; i++) {
        int u, v, x; cin >> u >> v >> x;
        if(x) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1);
    queue<int> q;

    int ans = binpow(n, k);

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        q.push(i);
        vis[i] = 1;
        int cnt = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            cnt++;
            for(int v: adj[u]) {
                if(vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }
        ans = (ans-binpow(cnt, k)+MOD)%MOD;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}