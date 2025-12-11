#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

int n;
set<pair<int, int>> s;

vector<int> tSort() {

    map<int, vector<int>> adj;
    map<int, int> deg;

    for(auto [u, v]: s) {
        adj[u].push_back(v);
        deg[v]++;
    }

    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) q.push(i);
    }

    vector<int> ans;

    while(!q.empty()) {

        int u = q.front(); q.pop();
        ans.push_back(u);

        for(int v: adj[u]) {
            if(--deg[v] == 0) q.push(v);
        }

    }

    return ans;

}

void solve() {

    cin >> n;
    s.clear();

    for(int i = 1; i < n; i++) {

        int u, v, x, y; cin >> u >> v >> x >> y;

        if(x > y) s.insert({ v, u });
        else s.insert({ u, v });

    }

    vector<int> a = tSort();
    vector<int> ans(n);

    for(int i = 0; i < n; i++) {
        ans[a[i]-1] = i+1;
    }

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}