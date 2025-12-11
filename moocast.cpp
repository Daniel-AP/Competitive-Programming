#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<tuple<double, double, double>> a(n);

    for(int i = 0; i < n; i++) {
        double x, y, z; cin >> x >> y >> z;
        a[i] = { x, y, z };
    }

    unordered_map<int, vector<int>> adj;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            double x1 = get<0>(a[i]), x2 = get<0>(a[j]);
            double y1 = get<1>(a[i]), y2 = get<1>(a[j]);
            double dist = sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

            if(dist <= get<2>(a[i])) {
                adj[i].push_back(j);
            }

        }
    }

    queue<int> q;

    int mx = 1;

    for(int i = 0; i < n; i++) {

        vector<bool> visited(n, false);

        visited[i] = true; q.push(i);
        int curr = 0;

        while(!q.empty()) {

            int k = q.front(); q.pop();
            mx = max(mx, ++curr);

            for(int j: adj[k]) {
                if(visited[j]) continue;
                visited[j] = true;
                q.push(j);
            }

        }
    
    }

    cout << mx << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int t; t = 1;

    // START_TIMER;

    while(t--) solve();

    // END_TIMER;

    return 0;

}