#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

int cnt(unordered_map<int, set<int>>& adj, int n) {

    unordered_set<int> visited;
    queue<int> q;

    int res = 0;

    for(auto& [ky, v]: adj) {

        if(visited.count(ky)) continue;

        q.push(ky); visited.insert(ky);
        res++;

        while(!q.empty()) {
            int k = q.front(); q.pop();
            for(int j: adj[k]) {
                if(visited.count(j)) continue;
                q.push(j); visited.insert(j);
            }
        }

    }

    return res;

}

void del(unordered_map<int, set<int>>& adj, int n, int target) {

    adj.erase(target);

    for(auto& [ky, v]: adj) {
        adj[ky].erase(target);
    }

}

void solve() {

    int n, m; cin >> n >> m;

    unordered_map<int, set<int>> adj;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    cout << (cnt(adj, n)  == 1 ? "YES" : "NO") << "\n";

    for(int i = 0; i < n-1; i++) {
        int x; cin >> x;
        del(adj, n, x);
        cout << (cnt(adj, n) == 1 ? "YES" : "NO") << "\n";   
    }

    int x; cin >> x;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}