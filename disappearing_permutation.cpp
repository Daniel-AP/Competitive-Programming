#include <bits/stdc++.h>
using namespace std;

#define int long long

set<int> visited;

int dfs(int node, int s, map<int, int>& adj_list) {

    visited.insert(node);
    
    if(adj_list[node] ==  0 || adj_list[node] == node) return s;
    if(visited.count(adj_list[node]) > 0) return s;


    return dfs(adj_list[node], s+1, adj_list);

}

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> p(n), d(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> d[i];

        map<int, int> adj_list;
        vector<int> cost(n+1);

        for(int i = 0; i < n; i++) {
            adj_list[p[i]] = i+1;
        }

        for(int i = 1; i <= n; i++) {
            dfs(p[d[i-1]-1], 1, adj_list);
            cost[i] = visited.size();
        }

        for(int i = 1; i <= n; i++) cout << cost[i] << " ";
        cout << endl;

        visited.clear();

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}