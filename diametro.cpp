#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> g;

pair<int, int> dfs(int node, int parent = -1) {

    pair<int, int> result = {0, node};

    for(int i: g[node]) {

        if(i == parent) continue;

        pair<int, int> sub = dfs(i, node);
        sub.first++;

        result = max(result, sub);

    }

    return result;

}

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        g = vector<vector<int>>(n, vector<int>());

        for(int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        pair<int, int> ans(0, 0);

        for(int i = 0; i < n-1; i++) {
            ans = max(dfs(i), ans);
        }

        cout << ans.first << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}