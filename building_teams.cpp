#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n, m; cin >> n >> m;
    unordered_map<int, vector<int>> adj_list;

    while(m--) {
        int a, b; cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    unordered_set<int> visited;
    vector<int> color(n+1, -1);
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        
        if(visited.count(i)) continue;

        q.push(i); visited.insert(i);
        color[i] = 1;

        while(!q.empty()) {

            int k = q.front(); q.pop();

            for(int j: adj_list[k]) {
                if(color[j] == color[k]) {
                    cout << "IMPOSSIBLE" << "\n";
                    return;
                }
                if(visited.count(j)) continue;

                color[j] = !color[k];
                q.push(j); visited.insert(j);

            }
        }

    }

    for(int i = 1; i <= n; i++) {
        cout << color[i]+1 << " ";
    }

    cout << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}