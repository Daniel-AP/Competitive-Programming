#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n, m; cin >> n >> m;

    vector<pair<int, int>> coords(n+1);

    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        coords[i] = { x, y };
    }

    unordered_map<int, vector<int>> adj;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n+1, false);
    queue<int> q;

    int mn_p = INF;

    for(int i = 1; i <= n; i++) {

        if(visited[i]) continue;

        visited[i] = true; q.push(i);
        int pos[] = { INF, 0, INF, 0 };

        while(!q.empty()) {

            int k = q.front(); q.pop();
            int x = coords[k].first, y = coords[k].second;

            pos[0] = min(pos[0], x); pos[1] = max(pos[1], x);
            pos[2] = min(pos[2], y); pos[3] = max(pos[3], y);

            for(int j: adj[k]) {
                if(visited[j]) continue;
                q.push(j); visited[j] = true;
            }

        }

        int per = 2*(pos[1]-pos[0])+2*(pos[3]-pos[2]);

        mn_p = min(mn_p, per);

    }

    cout << mn_p << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}